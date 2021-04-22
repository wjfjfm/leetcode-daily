#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int dp[101];
    int numDecodings(string s) {
        const int N = s.size();
        if (s[0] == '0') return 0;
        dp[1] = 1;
        dp[0] = 1;
        for(int i=1; i<N; i++) {
            const int num = (s[i-1] - '0') * 10 + s[i] - '0';
            if (num < 10 || num > 26) {
                if (s[i] != '0')
                    dp[i+1] = dp[i];
                else
                    dp[i+1] = 0;
            }
            else if (num == 10 || num == 20) dp[i+1] = dp[i-1];
            else dp[i+1] = dp[i] + dp[i-1];
        }
        return dp[N];
    }
};

int main() {
    string s;
    int result;
    Solution solution;
    s = "12";
    result = Solution().numDecodings(s);
    cout << result << endl;
    s = "226";
    result = Solution().numDecodings(s);
    cout << result << endl;
    s = "0";
    result = Solution().numDecodings(s);
    cout << result << endl;
    s = "06";
    result = Solution().numDecodings(s);
    cout << result << endl;
    s = "1201234";
    result = Solution().numDecodings(s);
    cout << result << endl;
    s = "230";
    result = Solution().numDecodings(s);
    cout << result << endl;
}

