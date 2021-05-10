#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    unordered_set<string> set;
    vector<int> lc;
    vector<int> rc;
    string S;
    int N;
    void go(string now, int a, int i, int l, int r) {
        if (i == N) {
            if(l == 0 && r == 0)set.insert(now);
            return;
        }
        if (S[i] == '(') {
            if (lc[i] >= l) go(now + '(', a+1, i+1, l, r);
            if (l > 0) go(now, a, i+1, l-1, r);
        }
        else if (S[i] == ')') {
            if (a > 0 && rc[i] >= r) go(now + ')', a-1, i+1, l, r);
            if (r > 0) go(now, a, i+1, l, r-1);
        }
        else {
            go(now + S[i], a, i+1, l, r);
        }

    }
public:
    vector<string> removeInvalidParentheses(string s) {
        N = s.size();
        S = s;
        lc.resize(N);
        rc.resize(N);
        int l = 0;
        int r = 0;
        for(int i=N-1; i>0; i--) {
            if (s[i] == '(') {
                l++;
            }
            else if (s[i] == ')') {
                r++;
            }
            lc[i-1] = l;
            rc[i-1] = r;
        }
        l = 0;
        r = 0;
        for(char c: s) {
            if (c == '(') l++;
            else if (c == ')') {
                if (l > 0) l--;
                else r++;
            }
        }
        if (l == 0 && r == 0) {
            vector<string> result = {s};
            return result;
        }
        else if (l + r == N) {
            vector<string> result = {""};
            return result;
        }
        go("", 0, 0, l, r);
        vector<string> result(set.begin(), set.end());
        return result;
    }
};

int main() {
    string s;
    vector<string> result;

    s = "()())()";
    result = Solution().removeInvalidParentheses(s);
    cout << s << ":"<< endl;
    for(string st: result) cout << st << endl;
    cout << endl;

    s = "(a)())()";
    result = Solution().removeInvalidParentheses(s);
    cout << s << ":"<< endl;
    for(string st: result) cout << st << endl;
    cout << endl;

    s = ")(";
    result = Solution().removeInvalidParentheses(s);
    cout << s << ":"<< endl;
    for(string st: result) cout << st << endl;
    cout << endl;

    s = ")))(((";
    result = Solution().removeInvalidParentheses(s);
    cout << s << ":"<< endl;
    for(string st: result) cout << st << endl;
    cout << endl;
}
