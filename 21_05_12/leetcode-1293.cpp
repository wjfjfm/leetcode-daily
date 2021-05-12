#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
private:
    int cost[40][40];
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        const int N = grid.size();
        const int M = grid[0].size();
        const int tx = N-1;
        const int ty = M-1;
        if (tx == 0 && ty == 0) return k >= grid[0][0] ? 0 : -1;
        vector<pair<int, int>> cur, next;
        memset(cost, 0x3f, 40 * 40 * sizeof(int));
        cost[0][0] = grid[0][0];

        cur.push_back(make_pair(0, 0));
        int step = 1;
        while(cur.size()) {
            // cout << "step " << step << endl;
            for(auto p: cur) {
                for(int i=0; i<4; i++) {
                    const int nx = p.first + dx[i];
                    if (nx < 0 || nx > tx) continue;
                    const int ny = p.second + dy[i];
                    if (ny < 0 || ny > ty) continue;
                    // cout << p.first << "," << p.second << "->" << nx << "," << ny << endl;

                    const int ncost = cost[p.first][p.second] + grid[nx][ny];
                    if (ncost >= cost[nx][ny] || ncost > k) continue;
                    if (nx == tx && ny == ty) return step;
                    cost[nx][ny] = ncost;
                    next.push_back(make_pair(nx, ny));
                    // cout << "   go!" << endl;
                }
            }
            swap(next, cur);
            next.clear();
            step++;
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> grid;
    int k, result;

    grid = {{0,1,1},
            {1,1,1},
            {1,0,0}};
    k = 1;
    result = Solution().shortestPath(grid, k);
    cout << result << endl;

    grid = {{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}};
    k = 1;
    result = Solution().shortestPath(grid, k);
    cout << result << endl;
}
