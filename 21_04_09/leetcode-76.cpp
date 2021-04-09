#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>
using namespace std;
typedef unsigned long long ull_t;
class SQ {
    public:
        int status;
        unsigned long long current;
        unordered_map<char, int> need;
        unordered_map<char, int> now;
        void insert_need(string t) {
            for (char c: t) {
                if (need.find(c) == need.end()) {
                    need[c] = 1;
                    current = current | ((ull_t)1 << (c - 'A'));
                }
                else {
                    need[c]++;
                }
            }
        }
        int in_queue(char c) {
            // cout << "in_queue: " << c << "   cur_status: " << status << "  return_status: ";
            if (need.find(c) == need.end()) return status;
            if (now.find(c) == now.end()) {
                now[c] = 1;
            }
            else {
                now[c]++;
            }
            if (need[c] == now[c]) {
                current = current & ~((ull_t)1 << (c - 'A'));
                status = current == 0;
            }
            // cout << status << endl;
            return status;
        }

        int de_queue(char c) {
            // cout << "de_queue: " << c << "   cur_status: " << status << "  return_status: ";
            if (need.find(c) == need.end()) return status;
            if (now.find(c) == now.end()) assert(false);
            else {
                now[c]--;
            }
            if (now[c] == need[c] - 1) {
                current = current | ((ull_t)1 << (c - 'A'));
                status = 0;
            }
            // cout << status << endl;
            return status;
        }

        SQ (string t) {
            current = 0;
            insert_need(t);
            status = current == 0;
        }


};
class Solution {
public:
    string minWindow(string s, string t) {
        SQ sq(t);
        vector<pair<char, int>> new_s;
        int p = -1;
        for (char c: s) {
            p++;
            if (sq.need.find(c) == sq.need.end()) continue;
            else new_s.push_back(make_pair(c, p));
        }
        int l = 0, r = 0;
        int status=0;
        const int N = new_s.size();
        if ( N == 0) return "";
        int ans_l = -1, ans_r, ans_size = 0x3fcfcfcf;
        int cur_l = 0, cur_r = 0, cur_size = 0;
        cur_l = new_s[0].second;

        while(status == 0 && r < N) {
            status = sq.in_queue(new_s[r].first);
            cur_r = new_s[r].second + 1;

            while (status == 1) {
                if (cur_r - cur_l < ans_size) {
                    ans_l = cur_l;
                    ans_r = cur_r;
                    ans_size = cur_r - cur_l;
                }
                status = sq.de_queue(new_s[l].first);
                l++;
                if (l >= N) break;
                cur_l = new_s[l].second;
            }

            r++;
        }
        // cout << ans_l << ' ' << ans_r << endl;
        if (ans_l <0) return "";
        return s.substr(ans_l, ans_r - ans_l);

    }
};

int main() {
    string s;
    string t;
    string ans;

    s = "ADOBECODEBANC";
    t = "ABC";
    ans = Solution().minWindow(s, t);
    cout << ans << endl;

    s = "a";
    t = "aa";
    ans = Solution().minWindow(s, t);
    cout << ans << endl;

    s = "ab";
    t = "b";
    ans = Solution().minWindow(s, t);
    cout << ans << endl;

    s = "a";
    t = "b";
    ans = Solution().minWindow(s, t);
    cout << ans << endl;
}
