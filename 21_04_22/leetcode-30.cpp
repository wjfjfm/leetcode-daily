#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
private:
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        const int N = s.size();
        int length = 0;
        for (string str: words) {
            length += str.size();
        }
        char* c = &s[0];
        vector<int> iter(words.size());
        unordered_set<string> set;
        for(int i=0; i<words.size(); i++) {
            iter[i] = i;
        }
        do {
            string str = "";
            for(int i: iter) {
                str.append(words[i]);
            }
            set.insert(str);
        } while (next_permutation(iter.begin(), iter.end()));
        vector<int> result;
        for(int i=0; i <= N-length; i++) {
            if(set.count(s.substr(i, length))) result.push_back(i);
        }
        return result;
    }
};

int main() {
    string s;
    vector<int> result;
    vector<string> words = {"foo","bar"};
    s = "barfoothefoobarman";
    result = Solution().findSubstring(s, words);
    cout << s;
    for (int i: result) cout << ' '<< i;
    cout << endl;

    s = "wordgoodgoodgoodbestword";
    result = Solution().findSubstring(s, words);
    cout << s;
    for (int i: result) cout << ' '<< i;
    cout << endl;
}
