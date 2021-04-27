#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
private:
    int find[60] = {};

public:
    int numDistinct(string s, string t) {
    const int N = t.size();
    vector<int> next(N + 1);
    vector<unsigned int> res(N + 1);
    vector<char> ns;
    int i = 1, j;
    for(char c: t){
        int *it = &find[c - 'A'];
        if (*it) {
            next[i] = *it;
            *it = i;
        }
        else {
            *it = i;
            next[i] = i;
        }
        i++;

    }
    for(char c: s) {
        if (find[c - 'A'])
            ns.push_back(c);
    }

    res[0] = 1;
    for(char c: ns) {
        i = find[c - 'A'];
        while (i != next[i]){
            res[i] += res[i - 1];
            i = next[i];
        }
        res[i] += res[i - 1];
        i = next[i];
    }
    return res[N];
    }
};

int main() {
    string s, t;
    int result;

    s = "rabbbit";
    t = "rabbit";
    result = Solution().numDistinct(s, t);
    cout << result << endl;

    s = "babgbag";
    t = "bag";
    result = Solution().numDistinct(s, t);
    cout << result << endl;
}
