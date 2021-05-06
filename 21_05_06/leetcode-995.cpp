#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int cur = 1;
        const int N = A.size();
        for(int i=N-1; i>0; i--) {
            A[i] = A[i] == A[i-1] ? true : false;
        }
        A.push_back(0);
        int result = 0;
        for(int i=0; i<=N-K; i++) {
            if (!A[i]) {
                result++;
                A[i+K] = !A[i+K];
            }
        }
        for(int i=N-K+1; i<N; i++) {
            if (!A[i]) return -1;
        }
        return result;

    }
};

int main() {
    // passed
    return 0;
}
