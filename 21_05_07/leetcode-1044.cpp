#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
    const int M = 1e7-9;
    int N;
    int find(string s, int n) {
        if (n >= s.size()) return -1;
        if (n <= 0) return 0;
        int hash = 0;
        int CE = 1;
        for(int i=0; i<n; i++) {
            hash = (hash * 26 + (s[i] - 'a')) % M;
            CE = CE * 26 % M;
        }
        hash = hash < 0 ? hash + M : hash;
        unordered_map<int, vector<int>> map;
        map[hash].push_back(0);

        for(int i=0; i+n<N; i++) {
            hash = (hash * 26 + (s[i+n] - 'a') - (s[i] - 'a') * CE) % M;
            hash = hash < 0 ? hash + M : hash;
            if (map.count(hash)) {
                for(int j: map[hash]) {
                    if (s.substr(j, n) == s.substr(i+1, n)) return i+1;
                }
            }
            map[hash].push_back(i+1);
        }
        return -1;
    }
public:
    string longestDupSubstring(string s) {
        N = s.size();
        int l = 0;
        int r = s.size();
        int p, q;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if ((p = find(s, m)) >= 0) {
                q = p;
                l = m;
            }
            else
                r = m;
        }
        if (l == 0) return "";
        return s.substr(q, l);
    }
};

int main() {
    string s;
    s = "banana";
    cout << Solution().longestDupSubstring(s) << endl;

    s = "abcd";
    cout << Solution().longestDupSubstring(s) << endl;
}

