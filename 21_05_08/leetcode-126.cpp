#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool next_to(string a, string b) {
        const int n = a.size();
        int i = 0;
        for(; i<n; i++) {
            if (a[i] == b[i]) continue;
            i++;
            for(; i<n; i++) {
                if (a[i] == b[i]) continue;
                return false;
            }
            return true;
        }
        return false;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> route;
        vector<vector<string>> nroute;
        vector<string> nwl;

        bool flag = true;
        for(auto it = wordList.begin(); it !=wordList.end(); it++) {
            if (*it == endWord) {
                wordList.erase(it);
                flag = false;
                break;
            }
        }

        if (flag) return route;

        nwl.push_back(beginWord);
        route.push_back(nwl);
        nwl.clear();

        vector<bool> used;
        while(route.size()) {
            flag = false;
            for(auto &v: route) {
                if (next_to(v.back(), endWord)) {
                    v.push_back(endWord);
                    nroute.push_back(v);
                    flag = true;
                }
            }
            if (flag) {
                swap(nroute, route);
                break;
            }
            used.clear();
            used.resize(wordList.size());
            for(auto &v: route) {
                for (int i=0; i<wordList.size(); i++) {
                    if (next_to(v.back(), wordList[i])) {
                        nroute.push_back(v);
                        nroute.back().push_back(wordList[i]);
                        used[i] = true;
                    }
                }
            }
            for(int i=0; i<wordList.size(); i++) {
                if (!used[i]) nwl.push_back(wordList[i]);
            }
            swap(nwl, wordList);
            nwl.clear();
            swap(nroute, route);
            nroute.clear();
        }
        return route;

    }
};

int main() {
    string beginWord, endWord;
    vector<string> wordList;
    vector<vector<string>> result;

    beginWord = "hit";
    endWord = "cog";
    wordList = {"hot","dot","dog","lot","log","cog"};
    result = Solution().findLadders(beginWord, endWord, wordList);
    for(auto v: result) {
        for(auto s: v) {
            cout << s << " -> ";
        }
        cout << endl;
    }
}
