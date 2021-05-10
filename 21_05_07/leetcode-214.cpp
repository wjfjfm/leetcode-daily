#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        const int N = s.size();

        vector<int> kmp(N, -1);
        for(int i=1; i<N; i++) {
            int j = kmp[i-1];
            while(j >=0 && s[i] != s[j+1]) {
                j = kmp[j];
            }
            if (s[j+1] == s[i]) {
                kmp[i] = j+1;
            }
        }
        for(int i=1; i<N; i++) {
            
        }
        for(int i: kmp) cout << i << ' ';
        return "";
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
