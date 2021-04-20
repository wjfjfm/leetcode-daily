#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int sums[1024];
    int N;
    bool trytry(int m, int bar) {
        int * it;
        int current = 0, target;
        while(m--) {
            target = current + bar;
            it = upper_bound(&sums[0], &sums[N+1], target);
            if (it == &sums[N+1]) return true;
            if (*--it == current) return false;
            current = *it;
        }
        return false;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        N = nums.size();
        sums[0] = 0;
        for(int i=0; i<N; i++) {
            sums[i+1] = sums[i] + nums[i];
        }
        int l = 0, r = sums[N];
        int target;
        while(l < r) {
            target = (l + r) / 2;
            if (trytry(m, target)) r = target;
            else l = target + 1;
        }
        return l;
    }
};

int main() {
    vector<int> nums;
    int m, result;
    nums = {7,2,5,10,8};
    m = 2;
    result = Solution().splitArray(nums, m);
    cout << result << endl;
}
