#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
private:
    int tool(vector<int>& nums, int k) {
        if (!k) return 0;
        int l = 0;
        int result = 0;
        map<int, int> map;
        for(int r = 0; r<nums.size(); r++) {
            map[nums[r]]++;
            while(map.size() > k) {
                if (map[nums[l]] > 1) map[nums[l]]--;
                else map.erase(nums[l]);
                l++;
            }
            result += r + 1 - l;
        }
        return result;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return tool(nums, k) - tool(nums, k-1);
    }
};

int main() {
    vector<int> A;
    int k;
    int result;

    A = {1,2,1,2,3};
    k = 2;
    result = Solution().subarraysWithKDistinct(A, k);
    cout << result << endl;

    A = {1,2,1,3,4};
    k = 3;
    result = Solution().subarraysWithKDistinct(A, k);
    cout << result << endl;
}
