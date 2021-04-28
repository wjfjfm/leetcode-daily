#include <vector>
#include <iostream>
using namespace std;
class Solution {
private:
    int sort(vector<int>& nums, int l, int r) {
        int m = (l + r) / 2;

        if (r - l <= 1) return 0;
        if (r - l == 2) {
            int result = 0;
            if (nums[l] > 2 * (long long)nums[l+1]) result = 1;
            if (nums[l] > nums[l+1]) swap(nums[l], nums[l+1]);
            return result;
        }
        int result = sort(nums, l, m) + sort(nums, m, r);

        // cout << "sorting ";
        // for (int i=l; i<m; i++) cout << nums[i] << ' ';
        // cout << "| ";
        // for (int i=m; i<r; i++) cout << nums[i] << ' ';
        // cout << endl;

        int cur = l;
        for (int i=m; i<r; i++) {
            while (cur < m && nums[cur] <= 2 * (long long)nums[i]) {
                cur++;
            }
            result += m - cur;
        }
        vector<int> tmp(&nums[l], &nums[m]);
        auto itl = tmp.begin();
        auto itle = tmp.end();
        auto itm = &nums[m];
        auto itr = &nums[r];

        for (int i=l; i<r; i++) {
            if ((itl != itle && itm != itr && *itl < *itm) || itm == itr) {
                nums[i] = *itl++;
            }
            else {
                nums[i] = *itm++;
            }
        }
        return result;
    }
public:
    int reversePairs(vector<int>& nums) {
        return sort(nums, 0, nums.size());
    }
};

int main() {
    vector<int> nums;
    int result;

    nums = {1,3,2,3,1};
    for (int i: nums) cout << i << ' ';
    cout << endl;
    result = Solution().reversePairs(nums);
    cout << result << endl;

    nums = {2, 4, 3, 5, 1};
    for (int i: nums) cout << i << ' ';
    cout << endl;
    result = Solution().reversePairs(nums);
    cout << result << endl;
}
