#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        const int N = nums.size();

        vector<int> sum(N + 1);
        sum[0]
        for(int i=0; i<N; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }

        sort(sum.begin(), sum.end());

        

    }
};

int main() {
    vector<int> nums;
    int lower, upper, result;

    lower = -2;
    upper = 2;
    nums = {-2, 5, -1};
    result = Solution().countRangeSum(nums, lower, upper);
    cout << result << endl;
}
