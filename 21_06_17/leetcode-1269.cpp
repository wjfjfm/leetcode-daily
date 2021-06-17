#include <iostream>
using namespace std;
#define M 1000000007
class Solution {
private:
    int dp1[260] = {};
    int dp2[260] = {};

public:
    int numWays(int steps, int arrLen) {
        dp1[1] = 1;
        for(int i=1; i<=steps; i++) {
            for(int j=1; j<=i+1 && j<=arrLen && j<= steps - i + 2; j++) {
                dp2[j] = ((dp1[j-1] + dp1[j]) % M + dp1[j+1]) % M;
            }
            swap(dp1, dp2);
        }
        return dp1[1];
    }
};

int main() {
    int steps, arrLen;
    steps = 2;
    arrLen = 4;
    cout << Solution().numWays(steps, arrLen) << endl;

    steps = 3;
    arrLen = 2;
    cout << Solution().numWays(steps, arrLen) << endl;

    steps = 4;
    arrLen = 2;
    cout << Solution().numWays(steps, arrLen) << endl;

    steps = 6;
    arrLen = 13;
    cout << Solution().numWays(steps, arrLen) << endl;

}
