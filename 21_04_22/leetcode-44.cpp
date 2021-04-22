#include <unordered_set>
#include<string>
#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        const int N = s.size();
        int index = 0;
        bool dp[2][N+1];
        memset(dp, 0, 2 * (N+1) * sizeof(bool));
        dp[index][0] = 1;
        for(char c: p) {
            if (c == '*') {
                for(int i=0; i<N; i++) {
                    if (dp[index][i]) {
                        dp[!index][i] = true;
                        dp[index][i+1] = true;
                    }
                }
                if (dp[index][N]) dp[!index][N] = true;
            }
            else if (c == '?') {
                for(int i=0; i<N; i++) {
                    if (dp[index][i]) {
                        dp[!index][i+1] = true;
                    }
                }
            }
            else {
                for(int i=0; i<N; i++) {
                    if (dp[index][i]) {
                        if (s[i] == c){
                            dp[!index][i+1] = true;
                        }
                    }
                }
            }
            index = !index;
            memset(dp[!index], 0, (N+1) * sizeof(bool));
        }
        return dp[index][N];

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
