#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    int dp[500][501];
    int sum[501];
    inline int max(int a, int b) {
        return a < b ? b : a;
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        const int N = stoneValue.size();
        for(int i=0; i<N; i++) {
            sum[i+1] = sum[i] + stoneValue[i];
        }
        for(int k = 2; k<=N; k++){
            for(int i=0; i+k<=N; i++) {
                for(int j = i+1; j<i+k; j++) {
                    if (sum[j] - sum[i] < sum[i+k] - sum[j])
                        dp[i][i+k] = max(dp[i][i+k], dp[i][j] + sum[j] - sum[i]);
                    else if (sum[j] - sum[i] > sum[i+k] - sum[j])
                        dp[i][i+k] = max(dp[i][i+k], dp[j][i+k] + sum[i+k] - sum[j]);
                    else if (dp[i][j] < dp[j][i+k])
                        dp[i][i+k] = max(dp[i][i+k], dp[j][i+k] + sum[i+k] - sum[j]);
                    else
                        dp[i][i+k] = max(dp[i][i+k], dp[i][j] + sum[j] - sum[i]);
                }
            }
        }
        return dp[0][N];
    }
};

int main() {
    vector<int> stoneValue;
    int result;

    stoneValue = {6,2,3,4,5,5};
    result = Solution().stoneGameV(stoneValue);
    cout << result << endl;

    stoneValue = {7,7,7,7,7,7,7};
    result = Solution().stoneGameV(stoneValue);
    cout << result << endl;

    stoneValue = {4};
    result = Solution().stoneGameV(stoneValue);
    cout << result << endl;

    stoneValue = {1,1,2};
    result = Solution().stoneGameV(stoneValue);
    cout << result << endl;
}
