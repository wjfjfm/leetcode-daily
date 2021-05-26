#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    inline int max(int a, int b) {
        return a < b ? b : a;
    }
    inline int min(int a, int b) {
        return a < b ? a : b;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int N = dungeon.size();
        const int M = dungeon[0].size();
        dungeon[N-1][M-1] = max(0, -dungeon[N-1][M-1]);
        for(int i=N-2; i>=0; i--) {
            dungeon[i][M-1] = max(0, dungeon[i+1][M-1] - dungeon[i][M-1]);
        }
        int min_need;
        for(int j=M-2; j>=0; j--) {
            for(int i=N-1; i>=0; i--) {
                if (i == N-1) min_need = dungeon[i][j+1];
                else min_need = min(dungeon[i][j+1], dungeon[i+1][j]);
                dungeon[i][j] = max(0, min_need - dungeon[i][j]);
            }
        }
        return dungeon[0][0] + 1;
    }
};

int main() {
    vector<vector<int>> dungeon;

    dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    cout << Solution().calculateMinimumHP(dungeon) << endl;
}
