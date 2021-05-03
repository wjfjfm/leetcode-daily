#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    int dp[101][101] = {};
    const int MODE = 1e9 + 7;
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int N = group.size();
        int cost, value, target;
        dp[0][0] = 1;
        for(int i=0; i<N; i++) {
            cost = group[i];
            value = profit[i];
            for(int j=n-cost; j>=0; j--) {
                for(int k=minProfit; k>=0; k--) {
                    target = k + value > minProfit ? minProfit : k + value;
                    dp[j+cost][target] = (dp[j+cost][target] + dp[j][k]) % MODE;
                }
            }
        }
        int result = 0;
        for(int i=0; i<=n; i++) {
           result = (result + dp[i][minProfit]) % MODE;
        }
        return result;
    }
};

int main() {
    int n, minProfit;
    vector<int> group, profit;

    n = 5;
    minProfit = 3;
    group = {2, 2};
    profit = {2, 3};
    cout << Solution().profitableSchemes(n, minProfit, group, profit) << endl;

    n = 10;
    minProfit = 5;
    group = {2, 3, 5};
    profit = {6, 7, 8};
    cout << Solution().profitableSchemes(n, minProfit, group, profit) << endl;
}
