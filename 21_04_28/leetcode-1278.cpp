#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
private:
    int cost[100][100] = {};
    int dp[101][101] = {};
    inline int min(int a, int b) {
        return a < b ? a : b;
    }
public:
    int palindromePartition(string s, int k) {
        const int n = s.size();
        for(int i=1; i<n; i++) {
            int cur_cost = 0;
            for(int j=1; i-j >= 0 && i+j < n; j++) {
                if (s[i-j] != s[i+j]) cur_cost++;
                cost[i-j][i+j] = cur_cost;
            }
        }
        for(int i=1; i<n; i++) {
            int cur_cost = 0;
            for(int j=1; i-j >= 0 && i+j-1 < n; j++) {
                if (s[i-j] != s[i+j-1]) cur_cost++;
                cost[i-j][i+j-1] = cur_cost;
            }
        }
        memset(dp, 0x3f, 101 * 101 * sizeof(int));
        dp[0][0] = 0;
        for(int i=0; i<k; i++) {
            for(int j=0; j<n; j++) {
                for(int l=j+1; l<n+1; l++) {
                    dp[i+1][l] = min(dp[i+1][l], dp[i][j] + cost[j][l-1]);
                }
            }
        }
        for(int i=1; i<k; i++) {
            dp[k][n] = min(dp[k][n], dp[i][n]);
        }
        return dp[k][n];

    }
};

int main() {
    string s;
    int k, result;

    s = "abc";
    k = 2;
    result = Solution().palindromePartition(s, k);
    cout << s << ' ' << k << ' '<< result << endl;

    s = "aabbc";
    k = 3;
    result = Solution().palindromePartition(s, k);
    cout << s << ' ' << k << ' '<< result << endl;

    s = "leetcode";
    k = 8;
    result = Solution().palindromePartition(s, k);
    cout << s << ' ' << k << ' '<< result << endl;
}
