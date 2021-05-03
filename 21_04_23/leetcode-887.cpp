#include <iostream>
using namespace std;
class Solution {
private:
    int dp[100][10001] = {};
    int l[100] = {};
    int r[100] = {};

    void find_dp(int k, int n) {
        if (k == 0) return;
        while(l[k-1] + r[k] < n) {
            if(!dp[k-1][l[k-1]]) find_dp(k-1, l[k-1]);
            while(dp[k-1][l[k-1]] > dp[k][r[k]]) {
                l[k-1]--;
                r[k]++;
            }
            dp[k][l[k-1] + r[k] + 1] = dp[k][r[k]] + 1;
            l[k-1]++;
        }
    }

public:
    int superEggDrop(int k, int n) {
        if (k==1) return n;
        for (int i=1; i<n; i++) {
            dp[0][i] = i;
        }
        find_dp(k-1, n);
        return dp[k-1][n];
    }
};


int main() {
    int k, n, result;

    k = 2;
    n = 6;
    result = Solution().superEggDrop(k, n);
    cout << k << ' ' << n << ' ' << result << endl;

    k = 3;
    n = 14;
    result = Solution().superEggDrop(k, n);
    cout << k << ' ' << n << ' ' << result << endl;
}

