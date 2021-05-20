#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        if (s.size() == 0) return result;
        unordered_map<char, vector<vector<int>>> cur, next;
        int i = 0;
        for(auto str: wordDict) {
            vector<int> tmp = {i, 0};
            cur[str[0]].push_back(tmp);
            i++;
        }
        i = 0;
        for(char c: s) {
            i++;
            for(auto &v: cur[c]) {
                if (wordDict[v[0]].size() - 1 == v[1]) {
                    v.push_back(v[0]);
                    v[1] = 0;
                    if (i == s.size()) {
                        next['+'].push_back(v);
                    }
                    else for(int i=0; i<wordDict.size(); i++) {
                        v[0] = i;
                        next[wordDict[i][0]].push_back(v);
                    }
                }
                else {
                    v[1]++;
                    next[wordDict[v[0]][v[1]]].push_back(v);
                }
            }
            cur.clear();
            swap(cur, next);
        }
        for(auto v: cur['+']) {
            string tmp = wordDict[v[2]];
            for(int i=3; i<v.size(); i++) {
                tmp += ' ';
                tmp += wordDict[v[i]];
            }
            result.push_back(tmp);
        }
        return result;
    }
};

int main() {
    vector<string> wordDict, result;
    string s;

    wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
    s = "pineapplepenapple";
    result = Solution().wordBreak(s, wordDict);
    cout << s << endl;
    for(auto str: result) cout << str << endl;
    cout << endl;

}
