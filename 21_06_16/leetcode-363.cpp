class Solution {
private:
    int sum[101][101] = {};
    inline int get_sum(int a1, int a2, int b1, int b2) {
        return sum[a1+1][a2+1] + sum[b1][b2] - sum[a1+1][b2] - sum[b1][a2+1];
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        const int N = matrix.size();
        const int M = matrix[0].size();
        for(int i=0; i<M; i++) {
            sum[1][i+1] = sum[1][i] + matrix[0][i];
        }
        for(int i=1; i<N; i++) {
            for(int j=0; j<M; j++) {
                sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + matrix[i][j];
            }
        }
        int result = 0xcfcfcfcf;
        int tmp;
        for(int a1=0; a1<N; a1++) {
            for(int a2=0; a2<M; a2++) {
                for(int b1=0; b1<=a1; b1++) {
                    for(int b2=0; b2<=a2; b2++) {
                        tmp = get_sum(a1, a2, b1, b2);
                        if (tmp <= k && tmp > result) {
                            result = tmp;
                        }
                    }
                }
            }
        }
        return result;
    }
};
