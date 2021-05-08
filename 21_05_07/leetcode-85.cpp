#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    inline int max(int a, int b) {
        return a > b ? a : b;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int N = matrix.size();
        if (N == 0) return 0;
        const int M = matrix[0].size();
        vector<vector<int>> mat(N);
        for(auto &i: mat) i.resize(M);
        for(int j=0; j<M; j++) {
            mat[N-1][j] = matrix[N-1][j] == '1' ? 1 : 0;
        }
        for(int j=0; j<M; j++) {
            for(int i=N-2; i>=0; i--) {
                mat[i][j] = matrix[i][j] == '1' ? mat[i+1][j] + 1 : 0;
            }
        }
        vector<pair<int, int>> q;
        int result = 0;
        int p;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                p = j;
                while(q.size() > 0 && q.back().first >= mat[i][j]) {
                    p = q.back().second;
                    result = max(result, q.back().first * (j - p));
                    q.pop_back();
                }

                q.push_back(make_pair(mat[i][j], p));
            }
            while (q.size() > 0) {
                p = q.back().second;
                result = max(result, q.back().first * (M - p));
                q.pop_back();
            }
        }
        return result;
    }
};

int main() {
    vector<vector<char>> matrix;

    matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << Solution().maximalRectangle(matrix) << endl;

    matrix = {};
    cout << Solution().maximalRectangle(matrix) << endl;

    matrix = {{'0'}};
    cout << Solution().maximalRectangle(matrix) << endl;

    matrix = {{'1'}};
    cout << Solution().maximalRectangle(matrix) << endl;

    matrix = {{'0', '0'}};
    cout << Solution().maximalRectangle(matrix) << endl;
}
