#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    inline int min(int a, int b) {
        return a < b ? a : b;
    }

    vector<vector<int>> mem;

    int dp(string &s, int l, int r) {
        if (l >= r) return 0;
        if (mem[l][r] >= 0) return mem[l][r];

        if (s[l] == s[r]) return mem[l][r] = dp(s, l+1, r-1);

        int result;
        result = 1 + min(dp(s, l+1, r), dp(s, l, r-1));
        return mem[l][r] = result;
    }


public:
    int minInsertions(string s) {
        const int N = s.size();
        mem = vector<vector<int>>(N, vector<int>(N, -1));
        return dp(s, 0, N-1);

    }
};

int main() {
    string s;


    s = "zzazz";
    cout << s << endl << Solution().minInsertions(s) << endl << endl;

    s = "mbadm";
    cout << s << endl << Solution().minInsertions(s) << endl << endl;

    s = "leetcode";
    cout << s << endl << Solution().minInsertions(s) << endl << endl;

    s = "g";
    cout << s << endl << Solution().minInsertions(s) << endl << endl;

    s = "no";
    cout << s << endl << Solution().minInsertions(s) << endl << endl;
}
