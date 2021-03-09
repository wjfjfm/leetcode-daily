#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string removeDuplicates(string S) {
        vector<char> stack;
        for(char c: S){
            if(stack.size() == 0 || c != stack.back()) stack.push_back(c);
            else stack.pop_back();
        }
        string result(stack.begin(), stack.end());
        return result;
    }
};

int main(){
    string S = "abbaca";
    string answer = "ca";
    assert(Solution().removeDuplicates(S) == answer);
    cout << "Test PASS!" << endl;
    return 0;
}
