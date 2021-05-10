#include <iostream>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int count[10] = {0, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000};
        int tens[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
        int a = n;
        int k = -1;
        while(a) {
            k++;
            a /= 10;
        }
        int result = 0;
        for(int i=k; i>=0; i--) {
            int top = n / tens[i];
            n = n % tens[i];
            result += count[i] * top;
            if (top > 1) result += tens[i];
            else if (top == 1) (result += n + 1);
        }
        return result;
    }
};

int main() {
    int n, result;

    n = 13;
    result = Solution().countDigitOne(n);
    cout << n << ": " << result << endl;

    n = 20;
    result = Solution().countDigitOne(n);
    cout << n << ": " << result << endl;

    n = 10000;
    result = Solution().countDigitOne(n);
    cout << n << ": " << result << endl;
}
