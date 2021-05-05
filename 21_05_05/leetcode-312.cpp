#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    int dp[502][502] = {};
    inline int max(int a, int b) {
        return a > b ? a : b;
    }

public:
    int maxCoins(vector<int>& nums) {
        const int N = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        for(int d=2; d<=N+1; d++) {
            for(int i=0; i+d<=N+1; i++) {
                for(int j=i+1; j<=i+d-1; j++) {
                    dp[i][i+d] = max(dp[i][i+d], dp[i][j] + dp[j][i+d] + nums[i]*nums[j]*nums[i+d]);
                }
            }
        }
        return dp[0][N+1];
    }
};

int main() {
    vector<int> nums;
    int result;

    nums = {3, 1, 5, 8};
    result = Solution().maxCoins(nums);
    cout << result << endl;

    nums = {1, 5};
    result = Solution().maxCoins(nums);
    cout << result << endl;

}
