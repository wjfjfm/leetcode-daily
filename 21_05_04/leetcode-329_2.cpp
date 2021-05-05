#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    int prefix[200][200] = {};
    vector<pair<int, int>> next[200][200];

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int N = matrix.size();
        const int M = matrix[0].size();

        bool flag = true;
        for(int i=0; i<N; i++) {
            for (int j=1; j<M; j++) {
                if (matrix[i][j-1] > matrix[i][j]) {
                    next[i][j].push_back(make_pair(i, j-1));
                    prefix[i][j-1]++;
                }
                else if (matrix[i][j-1] < matrix[i][j]) {
                    next[i][j-1].push_back(make_pair(i, j));
                    prefix[i][j]++;
                }
            }
        }
        for(int i=1; i<N; i++) {
            for (int j=0; j<M; j++) {
                if( matrix[i-1][j] > matrix[i][j]) {
                    next[i][j].push_back(make_pair(i-1, j));
                    prefix[i-1][j]++;
                }
                else if( matrix[i-1][j] < matrix[i][j]) {
                    next[i-1][j].push_back(make_pair(i, j));
                    prefix[i][j]++;
                }
            }
        }

        vector<pair<int, int>> *now = new vector<pair<int, int>>();
        vector<pair<int, int>> *fut = new vector<pair<int, int>>();

        for(int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (prefix[i][j] == 0) now->push_back(make_pair(i, j));
            }
        }
        int result = 0;
        while (now->size() > 0) {
            for (auto p: *now) {
                for (auto n: next[p.first][p.second]) {
                    // cout << p.first << ',' << p.second << " -> " << n.first << ',' << n.second << endl;
                    prefix[n.first][n.second]--;
                    if (prefix[n.first][n.second] == 0)
                        fut->push_back(n);
                }
            }
            result++;
            // cout << endl;
            swap(now, fut);
            fut->clear();
        }

        return result;
    }
};

int main() {
    vector<vector<int>> matrix;

    matrix = {{9,9,4},{6,6,8},{2,1,1}};
    cout << Solution().longestIncreasingPath(matrix) << endl;
}
