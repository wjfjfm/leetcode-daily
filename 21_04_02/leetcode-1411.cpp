#include <iostream>
class Solution {
public:
    int numOfWays(int n) {
    long long aba = 6, abc = 6;
    long long  aba_n, abc_n;
    const int base = 1000000007;
    for(int i=1; i<n; i++) {
        if (i & 1) {
            aba_n = (aba * 3 + abc * 2 ) % base;
            abc_n = (aba * 2 + abc * 2 ) % base;
        }
        else {
            aba = (aba_n * 3 + abc_n * 2 ) % base;
            abc = (aba_n * 2 + abc_n * 2 ) % base;
        }
    }

    return (int)(n & 1 ? (abc + aba) % base : (abc_n + aba_n) % base);

    }
};


