#include <queue>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int N, M;
    vector<vector<bool>> active;
    vector<vector<int>> height;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    inline int min(int a, int b) {
        return a < b ? a : b;
    }
    inline int max(int a, int b) {
        return a > b ? a : b;
    }

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        N = heightMap.size();
        M = heightMap[0].size();
        active = vector<vector<bool>> (N, vector<bool> (M, false));
        height = vector<vector<int>> (N, vector<int> (M, 0x3f3f3f3f));
        vector<pair<int, int>> tmp;
        for(int i=0; i<N; i++) {
            tmp.push_back(make_pair(heightMap[i][0], i*M));
            tmp.push_back(make_pair(heightMap[i][M-1], i*M + M - 1));
            active[i][0] = true;
            height[i][0] = heightMap[i][0];
            active[i][M-1] = true;
            height[i][M-1] = heightMap[i][M-1];
        }
        for(int i=1; i<M-1; i++) {
            tmp.push_back(make_pair(heightMap[0][i], i));
            tmp.push_back(make_pair(heightMap[N-1][i], (N-1)*M + i));
            active[0][i] = true;
            height[0][i] = heightMap[0][i];
            active[N-1][i] = true;
            height[N-1][i] = heightMap[N-1][i];
        }
        que = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> (tmp.begin(), tmp.end());
        while(que.size()) {
            auto p = que.top();
            que.pop();
            // cout << p.first << ' ' << p.second << endl;
            const int x = p.second / M;
            const int y = p.second % M;
            if (!active[x][y]) continue;
            active[x][y] = false;
            for (int i=0; i<4; i++) {
                const int nx = x + dx[i];
                const int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx > N-1 || ny > M-1) continue;
                int tmp_height = max(min(height[nx][ny], height[x][y]), heightMap[nx][ny]);
                if (tmp_height < height[nx][ny]) {
                    active[nx][ny] = true;
                    height[nx][ny] = tmp_height;
                    que.push(make_pair(tmp_height, nx * M + ny));
                }
            }
        }
        int result = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                result += height[i][j] - heightMap[i][j];
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> heightMap;
    int result;

    heightMap = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    cout << Solution().trapRainWater(heightMap) << endl;
}
