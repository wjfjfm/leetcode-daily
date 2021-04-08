#include <vector>
#include <iostream>
#include <assert.h>
using namespace std;

class Solution {
private:
long long merge(vector<int>::iterator l, vector<int>::iterator r) {
    const int size = r - l;
    if (size <= 1) return 0;
    if (size == 2) {
        if (*l <= *(l+1)) return 0;
        else {
            swap(*l, *(l+1));
            return 2;
        }
    }
    long long result = 0;
    auto m = (l + (r - l) / 2);
    result += merge(l, m);
    result += merge(m, r);
    vector<int> tmp(l, r);
    auto tl = tmp.begin();
    const auto tr = tmp.end();
    auto tm = (tl + (tr - tl) / 2);
    auto pt = tm;
    while(l != r) {
        if (tl == tm || (tl != tm && pt != tr && *tl > *pt)) {
            assert(l != r);
            assert(pt != tr);
            *l++ = *pt++;
            result += tm - tl;

        }
        else {
            assert(l != r);
            assert(tl != tr);
            *l++ = *tl++;
            result += pt - tm;
        }
    }
    return result;

}

public:
    int reversePairs(vector<int>& nums) {
        return merge(nums.begin(), nums.end()) / 2;
    }
};

int main() {
    vector<int> nums;
    int result;
    nums = {7, 5, 6, 4};
    result = Solution().reversePairs(nums);
    cout << result << endl;
}
