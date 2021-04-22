#include <unordered_set>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    int N;
    vector<vector<int>> Next;
    void next(const string &s) {
        auto v = new vector<int>();
        auto n = new vector<int>();

        v->push_back(0);
        for(int i=1; i<N; i++) {
            for(int j: *v) {
                if (s[j] == s[i]) {
                    Next[j].push_back(i + 1);
                    if (j > 0) n->push_back(j - 1);
                }
            }
            swap(n, v);
            n->clear();
            v->push_back(i);
            v->push_back(i-1);
        }
        delete v;
        delete n;
    }
public:
    int minCut(string s) {
        N = s.size();
        Next.resize(N);
        for(int i=0; i<N; i++) {
            Next[i].push_back(i+1);
        }
        next(s);

        auto cur = new unordered_set<int>();
        auto next = new unordered_set<int>();

        cur->insert(0);

        int result = 0;

        while(true) {
            for(int c: *cur) {
                for(int to: Next[c]) {
                    if (to == N) {
                        delete cur;
                        delete next;
                        return result;
                    }
                    next->insert(to);
                }
            }
            swap(cur, next);
            next->clear();
            result++;
        }
        assert(false);
        return 0;
    }
};

int main() {
    string s;
    int result;

    s = "aab";
    result = Solution().minCut(s);
    cout << s << ' ' <<  result << endl;

    s = "a";
    result = Solution().minCut(s);
    cout << s << ' ' <<  result << endl;

    s = "ab";
    result = Solution().minCut(s);
    cout << s << ' ' <<  result << endl;

    s = "aaabaa";
    result = Solution().minCut(s);
    cout << s << ' ' <<  result << endl;

    s = "abcdadcba";
    result = Solution().minCut(s);
    cout << s << ' ' <<  result << endl;

    s = "ladajfl";
    result = Solution().minCut(s);
    cout << s << ' ' <<  result << endl;
}
