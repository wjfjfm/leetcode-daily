#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lnum, rnum, mnum;
        int max_to_min;
        lnum = nums[0];
        rnum = nums.back();
        if (lnum < rnum) return lnum;
        else {
            max_to_min = lnum;
        }
        int low = *upper_bound (nums.begin(), nums.end(), -1e5,
            [&](int a, int b) {
                a = a >= max_to_min ? a - 1e9 : a;
                b = b >= max_to_min ? b - 1e9 : b;
                return a < b;
            });
        return low;
    }
};

int main() {
    vector<int> nums;
    int results;
    nums = {4,5,6,7,0,1,2};
    results = Solution().findMin(nums);
    cout << results << endl;
    nums = {1};
    results = Solution().findMin(nums);
    cout << results << endl;

}
