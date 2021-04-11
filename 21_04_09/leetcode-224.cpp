#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        int l = 0, r = s.size();
        bool reverse = 0;
        int result = 0;
        vector<bool> op_stack;
        bool current = 1;
        bool pre = 1;
        while (l < r) {
            while (l < r && s[l] == ' ') l++;
            if (s[l] == '(') {
                op_stack.push_back(pre);
                current = pre ? current : !current;
                l++;
                pre = 1;
            }
            else if (s[l] == ')') {
                current = op_stack.back() ? current : !current;
                op_stack.pop_back();
                l++;
            }
            else if (s[l] == '+') {
                pre = 1;
                l++;
            }
            else if (s[l] == '-') {
                pre = 0;
                l++;
            }
            else {
                int val = 0;
                while (l < r && s[l] - '0' < 10 && s[l] - '0' >= 0) {
                    val = val * 10 + (s[l] - '0');
                    l++;
                }
                val = pre ^ current ? -val : val;
                // cout << "val: " << val << "  " << "result: " << result << endl;
                result += val;
            }
        }
        return result;
    }
};

int main() {
    string s;
    int result;

    s = "1 + 1";
    result = Solution().calculate(s);
    cout << result << endl;

    s = " 2-1 + 2 ";
    result = Solution().calculate(s);
    cout << result << endl;

    s = "(1+(4+5+2)-3)+(6+8)";
    result = Solution().calculate(s);
    cout << result << endl;

    s = "1 + 1";
    result = Solution().calculate(s);
    cout << result << endl;


}
