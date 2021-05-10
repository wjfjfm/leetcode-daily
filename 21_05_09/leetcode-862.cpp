#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
private:
    int N;
    vector<int> sum;
    map<int, int> asum;
public:
    int shortestSubarray(vector<int>& A, int K) {
        N = A.size();
        sum.resize(N + 1);
        int max_num = 0;
        for(int i=0; i<N; i++) {
            if (A[i] >= K) return 1;
            sum[i+1] = sum[i] + A[i];
            if (sum[i+1] > max_num) {
                max_num = sum[i+1];
                asum[sum[i+1]] = i+1;
            }
        }
        int result = N+1;
        for(auto it: asum) {
            cout << it.first << ' ' << it.second << endl;
        }
        for(int i=0; i<N; i++) {
            if (A[i] <= 0) continue;
            while(asum.size() && asum.begin()->second <= i) asum.erase(asum.begin());
            if (asum.size() == 0 || sum[i] + K < asum.begin()->first) {
                max_num = sum[i];
                int rb = N+1;
                if(asum.size()) rb = asum.begin()->second;
                for(int j=i+1; j<rb; j++) {
                    if (sum[j] > max_num) {
                        max_num = sum[j];
                        asum[max_num] = j;
                    }
                }
            }
            auto it = asum.lower_bound(sum[i] + K);
            if (it != asum.end()) {
                cout << "DEBUG: i=" << i << "  lower_bound=" << it->second << endl;
                if (it->second - i < result) result = it->second - i;
            }
            else {
                cout << "DEBUG: i=" << i << "  lower_bound=end"<< endl;

            }
        }
        if (result > N) return -1;
        return result;
    }
};

int main() {
    vector<int> A;
    int result, K;

    A = {1};
    K = 1;
    result = Solution().shortestSubarray(A, K);
    cout << result << endl;

    A = {1, 2};
    K = 4;
    result = Solution().shortestSubarray(A, K);
    cout << result << endl;

    A = {2, -1, 2};
    K = 3;
    result = Solution().shortestSubarray(A, K);
    cout << result << endl;

    A = {77,19,35,10,-14};
    K = 19;
    result = Solution().shortestSubarray(A, K);
    cout << result << endl;

    A = {18,83,-43,-18,60};
    K = 18;
    result = Solution().shortestSubarray(A, K);
    cout << result << endl;
}
