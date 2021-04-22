#include <string>
#include <unordered_set>
#include <iostream>
#include <memory>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        const int N = s.size();
        unique_ptr<unordered_set<int>> cur(new unordered_set<int>());
        unique_ptr<unordered_set<int>> next(new unordered_set<int>());
        cur->insert(0);
        for(char c: p) {
            if (c == '*') {
                int min_i = N+1;
                for (int i: *cur) {
                    min_i = i < min_i ? i : min_i;
                }
                for (int i=min_i; i<=N; i++) {
                    next->insert(i);
                }
            }
            else if (c == '?') {
                for (int i: *cur) {
                    if (i != N)
                        next->insert(i + 1);
                }
            }
            else {
                for (int i: *cur) {
                    if (i !=N && s[i] == c)
                        next->insert(i + 1);
                }
            }
            swap(cur, next);
            next->clear();
        }
        return (cur->count(N));

    }
};


int main() {
    string s, p;
    bool result;
    s = "aa";
    p = "a";
    result = Solution().isMatch(s, p);
    cout << result << endl;
    s = "aa";
    p = "*";
    result = Solution().isMatch(s, p);
    cout << result << endl;
    s = "cb";
    p = "?a";
    result = Solution().isMatch(s, p);
    cout << result << endl;
    s = "acdcb";
    p = "a*c?b";
    result = Solution().isMatch(s, p);
    cout << result << endl;
    s = "";
    p = "******";
    result = Solution().isMatch(s, p);
    cout << result << endl;

}
