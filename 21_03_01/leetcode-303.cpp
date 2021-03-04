#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> sums;

    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums.resize(n + 1);
        for (int i=0; i<n; i++){
            sums[i+1] = sums[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return sums[j+1] - sums[i];
    }
};

int main(){
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray = NumArray(nums);
    assert(numArray.sumRange(0, 2) == 1);
    assert(numArray.sumRange(2, 5) == -1);
    assert(numArray.sumRange(0, 5) == -3);

    cout << "Test PASS!" << endl;
}
