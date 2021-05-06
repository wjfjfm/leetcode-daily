#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int sum = 0;
        int result = 0;
        int index = 0;
        const int N = nums.size();
        while (sum < n) {
            if (index < N && nums[index] <= sum + 1) {
                sum += nums[index];
                index++;
            }
            else {
                sum += sum + 1;
                result++;
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums;
    int n;

    nums = {1, 3};
    n = 6;
    cout << Solution().minPatches(nums, n) << endl;

    nums = {1, 5, 10};
    n = 20;
    cout << Solution().minPatches(nums, n) << endl;

    nums = {1, 2, 2};
    n = 5;
    cout << Solution().minPatches(nums, n) << endl;
}
