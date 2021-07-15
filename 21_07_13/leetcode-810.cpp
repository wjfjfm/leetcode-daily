#include <vector>
using namespace std;

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        if (nums.size() % 2 == 0) return true;
        int result = 0;
        for(int i: nums) result = result ^ i;
        if (result == 0) return true;
        return false;
    }
};
