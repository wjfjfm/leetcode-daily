#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    int part_max[1000][1000] = {};
    int dp[101][1000] = {};
    inline int max(int a, int b) {
        return a > b ? a : b;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        const int K = k;
        const int N = prices.size();
        if (N == 0) return 0;
        for(int i=0; i<N; i++) {
            const int cur = prices[i];
            int max_val = 0;
            for (int j=i+1; j<N; j++) {
                max_val = max(max_val, prices[j] - cur);
                part_max[i][j] = max_val;
            }
        }

        for(int i=1; i<=K; i++) {
            for(int j=0; j<N; j++) {
                for(int k=j; k<N; k++) {
                    dp[i][k] = max(dp[i][k], dp[i-1][j] + part_max[j][k]);
                }
            }
        }

        return dp[k][N-1];

    }
};

int main() {
    int k, result;
    vector<int> prices;

    k = 2;
    prices = {};
    result = Solution().maxProfit(k, prices);
    cout << result << endl;

    k = 2;
    prices = {3,2,6,5,0,3};
    result = Solution().maxProfit(k, prices);
    cout << result << endl;

}
