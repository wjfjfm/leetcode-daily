#include <iostream>

class Solution {
public:
    int clumsy(int N) {
        int result = 0;
        int mul = N;
        N--;
        while(N > 0) {
            if (N > 0) {
                mul = mul * N;
                N--;
            }
            if (N > 0) {
                mul = mul / N;
                N--;
            }
            result += mul;
            mul = 0;
            if (N > 0) {
                result += N;
                N--;
            }
            if (N > 0) {
                mul = -N;
                N--;
            }
        }
        result += mul;
        return result;
    }
};


int main() {
    int N, result, answer;
    N = 4;
    answer = 7;
    result = Solution().clumsy(N);
    std::cout << "N: " << N << "  result: " << result << ((result == answer) ? " == " : " != ") << answer << std::endl;
    assert(result == answer);
    std::cout << "Test Pass!!!" << std::endl;
    return 0;

}
