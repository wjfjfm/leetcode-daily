#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size() + nums2.size();
        nums1.push_back(0x3f3f3f3f);
        nums2.push_back(0x3f3f3f3f);
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        auto it3 = it1;
        for(int i=0; i<(N+1)/2; i++){
            if(*it1 < *it2) {
                it3 = it1;
                it1++;
            }
            else {
                it3 = it2;
                it2++;
            }
        }
        if (N & 1) return (double)*it3;
        int next = *it1 < *it2 ? *it1 : *it2;
        return (double)(*it3 + next) / 2.0;
    }
};


int main() {
    vector<int> nums1, nums2;
    double result;

    nums1 = {1, 3};
    nums2 = {2};
    result = Solution().findMedianSortedArrays(nums1, nums2);
    cout << result << endl;

    nums1 = {1, 2};
    nums2 = {3, 4};
    result = Solution().findMedianSortedArrays(nums1, nums2);
    cout << result << endl;

    nums1 = {0, 0};
    nums2 = {0, 0};
    result = Solution().findMedianSortedArrays(nums1, nums2);
    cout << result << endl;

    nums1 = {};
    nums2 = {1};
    result = Solution().findMedianSortedArrays(nums1, nums2);
    cout << result << endl;
}
