#include <vector>
#include <string>
#include <iostream>
#include <bitset>
using namespace std;
typedef unsigned long long ull_t;

class Solution {
private:
    static bool charInclude(ull_t pattern, char c) {
        return (pattern & (ull_t)1 << (c - 'A')) > 0;
    }
    static void makeExist(ull_t &pattern, char c) {
        pattern = pattern | (ull_t)1 << (c - 'A');
    }
    static void makeNotExist(ull_t &pattern, char c) {
        pattern = pattern & ~( (ull_t)1 << (c - 'A'));
    }
    static void addCount(int *count, char c, int num) {
        count[c - 'A'] += num;
    }
    static bool allInclude(ull_t a, ull_t b) {
        return (~a & b) == 0;
    }
public:
    string minWindow(string s, string t) {
        vector<pair<char, int>> s1;
        int count[50];
        memset(count, 0, sizeof(int) * 50);

        ull_t pattern = 0;
        for (char c: t) {
            pattern = pattern | ((ull_t)1 << (c - 'A'));
        }
        int position = 0;
        for (char c: s) {
            if (charInclude(pattern, c)) {
                s1.push_back(make_pair(c, position));
            }
            position++;
        }
        int left = 0, right = 0;
        ull_t current = 0;
        int min_length = 0x3fffffff;
        int min_l = 0, min_r = 0;
        for (auto p: s1) {
            const char c = p.first;
            const int posi = p.second;
            makeExist(current, c);
            addCount(count, c, 1);
            while(left <= right && allInclude(current, pattern)) {
                const char c_l = s1[left].first;
                const int posi_l = s1[left].second;
                if (posi - posi_l + 1 < min_length){
                    min_length = posi - posi_l + 1;
                    min_l = posi_l;
                    min_r = posi;
                }
                addCount(count, c_l, -1);
                if (count[c_l - 'A'] == 0)
                    makeNotExist(current, c_l);

                left++;
            }
            right++;
        }
        return s.substr(min_l, min_length);
    }
};

int main() {
    string s, t, answer, result;
    s = "ADOBECODEBANC";
    t = "ABC";
    answer = "BANC";
    result = Solution().minWindow(s, t);
    cout << result << endl;
}

