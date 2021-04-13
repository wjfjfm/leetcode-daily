#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = prices.size();
        vector<int> dp1(N+2), dp2(N+2);
        int Min = 0x3f3f3f3f;
        for (int i=0; i<N; i++) {
            Min = min(Min, prices[i]);
            dp1[i+1] = max(dp1[i], prices[i] - Min);
        }
        int Max = 0xcfcfcfcf;
        for (int i=N-1; i>=0; i--) {
            Max = max(Max, prices[i]);
            dp2[i+1] = max(dp2[i+2], Max - prices[i]);
        }
        int result = 0xcfcfcfcf;
        for (int i=1; i<=N; i++) {
            result = max(result, dp1[i] + dp2[i]);
        }
        return result;
    }
};

int main() {
    vector<int> prices;
    int result;

    prices = {3,3,5,0,0,3,1,4};
    result = Solution().maxProfit(prices);
    cout << result << endl;
}
