#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
private:
    int dp[500][167] = {};
    inline int max(int a, int b) {
        return a<b ? b : a;
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        const int N = slices.size();
        const int n = N / 3;
        int result = 0;
        for(int i=1; i<N; i++) {
            for(int j=0; j<i && j <= n; j++) {
                dp[i+2][j+1] = max(dp[i+2][j+1], dp[i][j] + slices[i]);
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            }
        }
        result = max(dp[N][n], dp[N+1][n]);
        memset(dp, 0, 500 * 167 * sizeof(int));
        dp[2][1] = slices[0];
        for(int i=2; i<N-1; i++) {
            for(int j=1; j<i && j<=n; j++) {
                dp[i+2][j+1] = max(dp[i+2][j+1], dp[i][j] + slices[i]);
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            }
        }
        result = max(result, dp[N][n]);
        result = max(result, dp[N-1][n]);
        return result;
    }
};

int main() {
    vector<int> slices;
    int result;

    slices = {8,9,8,6,1,1};
    result = Solution().maxSizeSlices(slices);
    cout << result << endl;

    slices = {4,1,2,5,8,3,1,9,7};
    result = Solution().maxSizeSlices(slices);
    cout << result << endl;
}
