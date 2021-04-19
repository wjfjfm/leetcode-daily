#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const float l24 = 24 - 1e-5;
const float r24 = 24 + 1e-5;

class Solution {
private:
    static inline bool is24(float f) {
        return f < r24 && f > l24;
    }
    bool try_22(const vector<int>& nums) {
        vector<float> first;
        first.push_back(nums[0] + nums[1]);
        first.push_back(nums[0] - nums[1]);
        first.push_back(nums[0] * nums[1]);
        first.push_back((float)nums[0] / (float)nums[1]);
        vector<float> second;
        second.push_back(nums[2] + nums[3]);
        second.push_back(nums[2] - nums[3]);
        second.push_back(nums[2] * nums[3]);
        second.push_back((float)nums[2] / (float)nums[3]);
        for (float f1: first) {
            for (float f2: second) {
                if (is24(f1 + f2)) return true;
                if (is24(f1 - f2)) return true;
                if (is24(f1 * f2)) return true;
                if (is24(f1 / f2)) return true;
            }
        }
        return false;
    }

    bool try_13(const vector<int>& nums) {
        vector<float> first;
        first.push_back(nums[0] + nums[1]);
        first.push_back(nums[0] - nums[1]);
        first.push_back(nums[0] * nums[1]);
        first.push_back((float)nums[0] / (float)nums[1]);
        vector<float> second;
        for(float i: first) {
            second.push_back(i + nums[2]);
            second.push_back(i * nums[2]);
            second.push_back(i - nums[2]);
            second.push_back(nums[2] - i);
            second.push_back(i / (float)nums[2]);
            second.push_back((float)nums[2] / i);
        }
        for(float i: second) {
            if (is24(i + nums[3])) return true;
            if (is24(i * nums[3])) return true;
            if (is24(i - nums[3])) return true;
            if (is24(nums[3] - i)) return true;
            if (is24(i / (float)nums[3])) return true;
            if (is24((float)nums[3] / i)) return true;
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        do {
            if (try_22(nums)) return true;
            if (try_13(nums)) return true;
        } while (next_permutation(nums.begin(), nums.end()));
        return false;
    }
};

int main() {
    vector<int> nums;
    bool result;
    nums = {4, 1, 8, 7};
    result = Solution().judgePoint24(nums);
    cout << result << endl;
    assert(result);
    nums = {1, 2, 1, 2};
    result = Solution().judgePoint24(nums);
    cout << result << endl;
    assert(!result);
    nums = {5, 5, 8, 4};
    result = Solution().judgePoint24(nums);
    cout << result << endl;
    assert(result);
}
