#include <vector>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums) {
        int max_num = 0;
        for(int i: nums) max_num = i > max_num ? i : max_num;
        vector<bool> not_prime(max_num+1);
        vector<int> dp(max_num+1);
        vector<int> prime;
        for(int i=2; i<=max_num; i++) {
            if (not_prime[i]) continue;
            prime.push_back(i);
            int a = i + i;
            while(a <= max_num) {
                not_prime[a] = true;
                a += i;
            }
        }

        int min_pre = 0;
        int min_cur;
        for(int i: nums) {
            min_cur = min_pre + 1;
            if (!not_prime[i]) {
                if (dp[i] && dp[i] < min_pre + 1) {
                    min_cur = dp[i] < min_cur ? dp[i] : min_cur;
                }
                else {
                    dp[i] = min_pre + 1;
                }
            }
            else for(int p: prime) {
                if (i % p == 0) {
                    if (dp[p] && dp[p] < min_pre + 1) {
                        min_cur = dp[p] < min_cur ? dp[p] : min_cur;
                    }
                    else {
                        dp[p] = min_pre + 1;
                    }
                    while (i % p == 0) i = i / p;
                    if (i == 1) break;
                }
            }
            min_pre = min_cur;
        }
        return min_cur;
    }
};

int main() {
    vector<int> nums;
    nums = {2,3,3,2,3,3};
    cout << Solution().splitArray(nums) << endl;

    nums = {2,3,5,7};
    cout << Solution().splitArray(nums) << endl;
}
