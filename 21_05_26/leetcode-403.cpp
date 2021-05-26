#include <vector>
#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;


class Solution {
private:
    set<pair<int, int>> visited;
    unordered_set<int> stone_set;
    int target;
    bool go(int i, int s) {
        if (i == target) return true;
        const pair<int, int> tmp = make_pair(i, s);
        if (visited.count(tmp)) return false;
        visited.insert(tmp);
        if (s > 1 && stone_set.count(i + s - 1) && go(i + s - 1, s - 1)) return true;
        if (s > 0 && stone_set.count(i + s) && go(i + s, s)) return true;
        if (stone_set.count(i + s + 1) && go(i + s + 1, s + 1)) return true;
        return false;
    }
public:
    bool canCross(vector<int>& stones) {
        stone_set = unordered_set<int> (stones.begin(), stones.end());
        target = (*--stones.end());
        return go(0, 0);
    }
};

int main() {
    vector<int> stones;

    stones = {0,1,3,5,6,8,12,17};
    cout << Solution().canCross(stones) << endl;

    stones = {0,1,2,3,4,8,9,11};
    cout << Solution().canCross(stones) << endl;


}
