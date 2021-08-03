#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
using namespace std;

class Solution {
private:
    map<int, int> Map;
    int index = 0;
    inline int max(int a, int b) {
        return a > b ? a : b;
    }
    int get_next(int cur, int length) {
        cout << "Debug " << cur << " " << length << endl;
        vector<vector<vector<int>>> dp(length + 2, vector<vector<int>> (5, vector<int> (3)));
        dp[0][0][0] = 1;
        for(int i=0; i<length; i++) {
            for(int a=0; a<5; a++) {
                for(int b=0; b<3; b++) {
                    if (dp[i][a][b] == 0) continue;
                    dp[i+1][b][0] = max(dp[i+1][b][0], dp[i][a][b] + (Map[i+cur] - a) / 3);
                    if (Map[i+cur] - a >= 1 && Map[i+cur+1] - b >= 1 && Map[i+cur+2] >= 1)
                        dp[i+1][b+1][1] = max(dp[i+1][b+1][1], dp[i][a][b] + (Map[i+cur] - a - 1) / 3 + 1);
                    if (Map[i+cur] - a >= 2 && Map[i+cur+1] - b >= 2 && Map[i+cur+2] >= 2)
                        dp[i+1][b+2][2] = max(dp[i+1][b+2][2], dp[i][a][b] + (Map[i+cur] - a - 2) / 3 + 2);
                }
            }
        }
        return dp[length][0][0] - 1;

    }
public:
    int maxGroupNumber(vector<int>& tiles) {
        int min = 1000000001;
        int max = 0;
        vector<int> start;
        vector<int> length;
        for(int i: tiles) {
            Map[i]++;
            min = i < min ? i : min;
            max = i > max ? i : max;
        }
        auto pre = Map.begin()->first;
        start.push_back(pre);
        int len = 0;
        for(auto i=Map.begin(); i != Map.end(); i++) {
            if (i->first > pre + 1) {
                start.push_back(i->first);
                length.push_back(len);
                len = 1;
            }
            else{
                len++;
            }
            pre = i->first;
        }
        length.push_back(len);
        int result = 0;
        for(int i=0; i<start.size(); i++) {
            result += get_next(start[i], length[i]);
        }
        return result;
    }
};

int main() {
    vector<int> tiles;
    tiles = {2, 2, 2, 3, 4};
    cout << Solution().maxGroupNumber(tiles) << endl;

    tiles = {2, 2, 2, 3, 4, 1, 3};
    cout << Solution().maxGroupNumber(tiles) << endl;

    tiles = {1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5};
    cout << Solution().maxGroupNumber(tiles) << endl;

    tiles = {1,1,3,3,3,4,4,4,5,5,6,6,7,8,8,8,9,9,9,10};
    cout << Solution().maxGroupNumber(tiles) << endl;

    tiles = {1,1,2,2,2,2,2,3,3,3,3,4,4,4,4,4,4,5,5,6,6,6,6,6,7,7,7,7,8,8,8,9,9,10,10,10,10,11,11,11,12};
    cout << Solution().maxGroupNumber(tiles) << endl;

}
