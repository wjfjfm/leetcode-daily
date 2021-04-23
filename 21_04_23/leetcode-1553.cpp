#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
private:
    inline int min(const int a, const int b) {
        return a < b ? a : b;
    }
    unordered_map<int, int> map;
public:
    int minDays(int n) {
        if (map.count(n)) return map[n];
        if (n <= 1)
            return n;
        else
            return map[n] = min(n % 3 + 1 + minDays(n / 3), n % 2 + 1 + minDays(n / 2));
    }
};

int main() {
    int n, result;
    n = 1;
    result = Solution().minDays(n);
    cout << result << endl;
    n = 56;
    result = Solution().minDays(n);
    cout << result << endl;
}
