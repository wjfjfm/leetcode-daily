#include <assert.h>

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
 private:
    string S;
    int N;
    bool isNum(char c) {
        if (c - '0' >= 0 && c - '0' <= 9) return true;
        return false;
    }
    bool parseNums(int &a) {
        if (a >=N) return false;
        if (!isNum(S[a])) return false;
        do {
            a++;
        } while (isNum(S[a]) && a < N);
        return true;
    }
    bool isZS(int a, int b) {
        if (a >= b) return false;
        if (S[a] == '+' || S[a] == '-') a++;
        bool has_num = parseNums(a);
        if (a == b && has_num) return true;
        return false;
    }
    bool isXZ(int a, int b) {
        int has_num = 0;
        if (a >= b) return false;
        if (S[a] == '+' || S[a] == '-') a++;
        has_num += static_cast<int>(parseNums(a));
        if (a >= b) return false;
        if (S[a] != '.') return false;
        a++;
        has_num += static_cast<int>(parseNums(a));
        if (a == b && has_num) return true;
        return false;
    }



 public:
    bool isNumber(string s) {
        S = s;
        N = s.size();
        if (N == 0) return false;
        int a = 0;

        for (int i=0; i<N; i++) {
            if (S[i] == 'e' || S[i] == 'E') {
                if ((isZS(a, i) || isXZ(a, i)) && isZS(i+1, N)) return true;
                return false;
            }
        }
        if (isZS(a, N) || isXZ(a, N)) return true;
        return false;
    }
};

int main() {
    vector<string> is_num  = {"0.8", "2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"};
    vector<string> not_num = {"4e+", "abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"};

    for (string s : is_num) {
        cout << s << endl;
        assert(Solution().isNumber(s));
    }
    for (string s : not_num) {
        cout << s << endl;
        assert(!Solution().isNumber(s));
    }

    cout << "All PASS!!!" << endl;
}
