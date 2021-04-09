#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int N = nums.size();
        if (N == 1) return nums;
        vector<int> prefixMax(N+1), suffixMax(N+1);
        prefixMax[0] = nums[0];
        for(size_t i=1; i<N; i++) {
            prefixMax[i] = i % k == 0 ? nums[i] : max(nums[i], prefixMax[i-1]);
        }
        suffixMax[N-1] = nums[N-1];
        for(int i=N-2; i>=0; i--) {
            suffixMax[i] = i % k == 0 ? nums[i] : max(nums[i], suffixMax[i+1]);
        }
        vector<int> result;
        for (int i=0; i<N-k+1; i++) {
            result.push_back(max(prefixMax[i+k-1], suffixMax[i]));
        }
        return result;
    }
};

int main() {
    vector<int> nums, results;
    int k;
    nums = {1, -1};
    k = 1;
    results = Solution().maxSlidingWindow(nums, k);
    for (int i: results) {
        cout << i << ' ';
    }
    cout << endl;
}
