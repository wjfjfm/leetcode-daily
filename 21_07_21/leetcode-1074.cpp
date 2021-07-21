#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int N, M;
    inline int get_val(vector<vector<int>>& matrix, int a, int b) {
        if (a < 0 || b < 0) return 0;
        return matrix[a][b];
    }
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        M = matrix.size();
        if (M == 0) return 0;
        N = matrix[0].size();
        for(int j=1; j<N; j++) {
            matrix[0][j] = matrix[0][j-1] + matrix[0][j];
        }
        for(int i=1; i<M; i++) {
            matrix[i][0] = matrix[i-1][0] + matrix[i][0];
        }
        for (int i=1; i<M; i++) {
            for (int j=1; j<N; j++) {
                matrix[i][j] = matrix[i][j-1] + matrix[i][j] + matrix[i-1][j] - matrix[i-1][j-1];
            }
        }
        unordered_map<int, int> map;
        int v;
        int result = 0;
        for (int i=0; i<M; i++) {
            for (int j=i; j<M; j++) {
                map.clear();
                for(int k=N-1; k>=0; k--) {
                    v = matrix[j][k] - get_val(matrix, i-1, k);
                    result += map[v + target];
                    map[v]++;
                }
                result += map[target];
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> matrix;
    int target;

    matrix = {{0,1,0},{1,1,1},{0,1,0}};
    target = 0;
    cout << Solution().numSubmatrixSumTarget(matrix, target) << endl;

    matrix = {{1,-1},{-1,1}};
    target = 0;
    cout << Solution().numSubmatrixSumTarget(matrix, target) << endl;

    matrix = {{904}};
    target = 0;
    cout << Solution().numSubmatrixSumTarget(matrix, target) << endl;
}
