#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    int dp[200][200] = {};
    inline int max(int a, int b) {
        return a>b ? a : b;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int N = matrix.size();
        const int M = matrix[0].size();
        bool flag = true;
        while (flag) {
            flag = false;
            for(int i=0; i<N; i++) {
                for (int j=1; j<M; j++) {
                    if (matrix[i][j-1] > matrix[i][j]) {
                        if (dp[i][j-1] < dp[i][j] + 1) {
                            dp[i][j-1] = dp[i][j] + 1;
                            flag = true;
                        }
                    }
                    else if (matrix[i][j-1] < matrix[i][j]) {
                        if (dp[i][j] < dp[i][j-1] + 1) {
                            dp[i][j] = dp[i][j-1] + 1;
                            flag = true;
                        }
                    }
                }
            }
            for(int i=1; i<N; i++) {
                for (int j=0; j<M; j++) {
                    if( matrix[i-1][j] > matrix[i][j]) {
                        if (dp[i-1][j] < dp[i][j] + 1) {
                            dp[i-1][j] = dp[i][j] + 1;
                            flag = true;
                        }
                    }
                    else if( matrix[i-1][j] < matrix[i][j]) {
                        if (dp[i][j] < dp[i-1][j] + 1) {
                            dp[i][j] = dp[i-1][j] + 1;
                            flag = true;
                        }
                    }
                }
            }
        }
        int result = 0;
        for(int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                result = max(result, dp[i][j]);
            }
        }

        return result+1;
    }
};

int main() {
    vector<vector<int>> matrix;

    matrix = {{9,9,4},{6,6,8},{2,1,1}};
    cout << Solution().longestIncreasingPath(matrix) << endl;
}
