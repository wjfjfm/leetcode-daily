#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        if (s.size() == 0) return 0;
        char pre = s[0];
        string ns;
        ns += pre;
        for(char c: s) {
            if (c != pre) {
                ns += c;
                pre = c;
            }
        }
        cout << ns << endl;
        const int N = ns.size();
        int dp[100][100];
        for(int i=0; i<N; i++) {
            dp[i][i] = 1;
        }
        for(int i=1; i<N; i++) {
            for(int j=0; i+j<N; j++) {
                dp[j][j+i] = 2000000000;
                for(int k=0; k<i; k++) {
                    if (k != j && k != j+i  && ns[j] == ns[j+k] && ns[j+k] == ns[j+i]) dp[j][j+i] = min(dp[j][j+i], dp[j][j+k] + dp[j+k][j+i] - 1);
                    else dp[j][j+i] = min(dp[j][j+i], dp[j][j+k] + dp[j+k+1][j+i]);
                }
                if (i > 1 && ns[j] == ns[j+i]) dp[j][j+i] = min(dp[j][j+i], dp[j][j+i-1]);
            }
        }

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        return dp[0][N-1];
    }
};

int main() {
    string s;
    s= "aaabbb";
    cout << Solution().strangePrinter(s) << endl;

    s= "abcabc";
    cout << Solution().strangePrinter(s) << endl;

    s= "abacadaea";
    cout << Solution().strangePrinter(s) << endl;


    s= "ababa";
    cout << Solution().strangePrinter(s) << endl;

    s= "abaca";
    cout << Solution().strangePrinter(s) << endl;

    s= "aba";
    cout << Solution().strangePrinter(s) << endl;

    s= "baacdddaaddaaaaccbddbcabdaabdbbcdcbbbacbddcabcaaa";
    cout << Solution().strangePrinter(s) << endl;

    s= "gjovhnlwhomhvac";
    cout << Solution().strangePrinter(s) << endl;

}
