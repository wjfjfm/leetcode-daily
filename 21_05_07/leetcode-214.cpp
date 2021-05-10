#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        const int N = s.size();
        if (!N) return "";
        vector<int> kmp(N);
        int p = kmp[0] = -1;
        for(int i=0; i<N-1; i++) {
            while(p >= 0 && s[i] != s[p]) p = kmp[p];
            kmp[i+1] = ++p;
        }

        for(int i=1; i<N; i++) {
            int j = kmp[i];
            while(j >= 0 && s[i] == s[j]) {
                j = kmp[j];
            }
            kmp[i] = j;
        }
        int k = 0;
        int i = N-1;

        while(i > k) {
            if (s[i] == s[k]) {
                k++;
                i--;
            }
            else {
                k = kmp[k];
                if (k < 0) {
                    k = 0;
                    i--;
                }
            }
        }
        string result = "";
        for(int j = N-1; j>i+k; j--) result += s[j];
        result += s;

        return result;
    }
};

int main() {
    string s;

    s = "abcdabceabed";
    cout << s << endl << Solution().shortestPalindrome(s) << endl;

    s = "aacecaaa";
    cout << s << endl << Solution().shortestPalindrome(s) << endl;

    s = "abcd";
    cout << s << endl << Solution().shortestPalindrome(s) << endl;

    s = "aabababababaababaa";
    cout << s << endl << Solution().shortestPalindrome(s) << endl;
}
