#include <vector>
#include <iostream>
using namespace std;

class Solution {
int findMin_lr(vector<int>& nums, int l, int r) {
    if (r - l <= 1) return nums[r];
    int m = (l + r) / 2;
    long long result = 1e15;
    if (nums[l] >= nums[m]) result = findMin_lr(nums, l, m);
    if (nums[m] >= nums[r]) {
        int tmp = findMin_lr(nums, m, r);
        result = tmp < result ? tmp : result;
    }
    return result;


}
public:
    int findMin(vector<int>& nums) {
        if (nums.front() < nums.back()) return nums.front();
        return findMin_lr(nums, 0, nums.size() - 1);
    }
};

int main() {
    vector<int> nums = {2,2,2,0,1};
    int result = Solution().findMin(nums);
    cout << result << endl;
}
