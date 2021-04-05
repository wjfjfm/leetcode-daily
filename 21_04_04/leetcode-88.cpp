#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(nums1.begin(), nums1.begin() + m);
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        auto it3 = nums3.begin();
        while(it1 != nums1.end()) {
            if(it3 != nums3.end() && it2 != nums2.end() && *it2 > *it3 || it2 == nums2.end()){
                cout << "insert nums3" << endl;
                *it1++ = *it3++;
            }
            else {
                cout << "insert nums2" << endl;
                *it1++ = *it2++;
            }
        }
    }
};

int main() {
    vector<int> nums1, nums2;
    int m, n;
    nums1 = {1,2,3,0,0,0};
    m = 3;
    nums2 = {2,5,6};
    n = 3;
    Solution().merge(nums1, m, nums2, n);
    // DEBUG
    for(int i: nums1) {
        cout << i << ' ';
    }
    cout << endl;
    // DEBUG


}
