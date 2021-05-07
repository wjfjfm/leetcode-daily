#include <vector>
#include <iostream>
#include <set>
using namespace std;
class Solution {
private:
    int N, M;
    bool brok[11][11] = {};
    set<int> visited;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    vector<vector<int>> connection;
    vector<int> connect_to;

    inline int get(int index, int k) {
        return index + dx[k] * M + dy[k];
    }
    bool find(int index) {
        if (visited.count(index)) return false;
        visited.insert(index);
        for(int to: connection[index]) {
            if (connect_to[to]) continue;
            connect_to[index] = to;
            connect_to[to] = index;
            return true;
        }
        for(int to: connection[index]) {
            if (to == connect_to[index]) continue;
            if (find(connect_to[to])) {
                connect_to[index] = to;
                connect_to[to] = index;
                return true;
            }
        }
        return false;
    }


public:
    int domino(int n, int m, vector<vector<int>>& broken) {
        N = n;
        M = m;
        for(auto &p: broken) {
            brok[p[0]][p[1]] = true;
        }

        connection.resize(n * m + 1);;
        connect_to.resize(n * m + 1);
        int x, y, index;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if (brok[i][j]) continue;
                index = i * m + j + 1;
                for(int k=0; k<4; k++) {
                    x = i + dx[k];
                    y = j + dy[k];
                    if (0 <= x && x < n && 0 <= y && y < m && !brok[x][y]) {
                        connection[index].push_back(x * m + y + 1);
                    }
                }
            }
        }

        int result = 0;
        for(int i=0; i<n; i++) {
            for(int j=i&1; j<m; j+=2) {
                if (brok[i][j]) continue;
                visited.clear();
                if (find(i * m + j + 1)) result++;
            }
        }

        cout << "connection:" << endl;
        for (int i=1; i<=n*m; i++) {
            for(int j: connection[i]) {
                cout << i << " -> " << j << endl;
            }
            cout << endl;
        }

        cout << "connect_to:" << endl;
        for(int i=1; i<=n*m; i++) {
            if(connect_to[i]) cout << i << " -> " << connect_to[i] << endl;
        }
        return result;
    }
};

int main() {
    vector<vector<int>> broken;
    int n, m, result;

    n = 2;
    m = 3;
    broken = {{1, 0}, {1, 1}};
    result = Solution().domino(n, m, broken);
    cout << result << endl;

    n = 3;
    m = 3;
    broken = {};
    result = Solution().domino(n, m, broken);
    cout << result << endl;

    n = 2;
    m = 3;
    broken = {{1, 2}, {0, 0}};
    result = Solution().domino(n, m, broken);
    cout << result << endl;

    n = 2;
    m = 3;
    broken = {{1, 0}, {1, 1}};
    result = Solution().domino(n, m, broken);
    cout << result << endl;
}
