#include <vector>
#include <iostream>
using namespace std;
class Solution {
private:
    inline int max(int a, int b) {
        return a > b ? a : b;
    }
public:
    int maximumGap(vector<int>& nums) {
        const int N = nums.size();
        if (N < 2) return 0;
        sort(nums.begin(), nums.end());
        int result = 0;
        for(int i=1; i<N; i++) {
            result = max(result, nums[i] - nums[i-1]);
        }
        return result;
    }
};

int main() {
    vector<int> nums;
    int result;

    nums = {3, 6, 9, 1};
    result = Solution().maximumGap(nums);
    cout << result << endl;
}
