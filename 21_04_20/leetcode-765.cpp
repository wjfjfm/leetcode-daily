#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int ufs[64];
    bool flag[64] = {};
    inline int find(int a) {
        if (ufs[a] != a) {
            ufs[a] = find(ufs[a]);
        }
        return ufs[a];
    }
    inline void join(int a, int b) {
        const int sa = find(a);
        const int sb = find(b);
        if (sa == sb) return;
        ufs[sb] = sa;
    }

public:
    int minSwapsCouples(vector<int>& row) {
        const int mask = ~1;
        const int N = row.size();
        const int N2 = N >> 1;
        for(int i=0; i<N; i++) {
            row[i] >>= 1;
        }
        for(int i=0; i<N2; i++) {
            ufs[i] = i;
        }
        for(int i=0; i<N; i+=2) {
            if (row[i] == row[i+1]) continue;
            join(row[i], row[i+1]);
        }
        int result = 0;
        for(int i=0; i<N2; i++) {
            const int s = find(i);
            if (flag[s]) result++;
            else flag[s] = true;
        }
        return result;
    }
};

int main() {
    vector<int> row;
    int result;
    row = {0, 2, 1, 3};
    result = Solution().minSwapsCouples(row);
    cout << result << endl;
    row = {3, 2, 0, 1};
    result = Solution().minSwapsCouples(row);
    cout << result << endl;
}
