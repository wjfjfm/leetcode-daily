#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
private:
    int L;
    bool nextTo(const string &A, const string &B) {
        bool flag = 0;
        for(int i=0; i<B.size(); i++) {
            if (A[i] != B[i]){
                if (flag) return false;
                else flag = true;
            }
        }
        if (flag) return true;
        else return false;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) return 1;
        vector<string> *from = new vector<string>;
        vector<string> *to = new vector<string>;
        vector<string> *cur = new vector<string>;
        vector<string> *next_cur = new vector<string>;
        L = endWord.length();
        bool flag = 0;
        for(string s: wordList) {
            if (s.length() == L) {
                if (s == endWord) flag = 1;
                else (*from).push_back(s);
            }
        }
        if (!flag) return 0;
        int depth = 2;
        cur->push_back(beginWord);
        while(from->size() > 0 || cur->size()) {
            if (cur->size() == 0) return 0;

            for(string c: *cur) {
                if (nextTo(c, endWord)) {
                    return depth;
                }
            }

            for(string s: *from) {
                flag = false;
                for(string c: *cur){
                    if (nextTo(c, s)){
                        next_cur->push_back(s);
                        flag = true;
                        break;
                    }
                }

                if (flag) continue;
                else (*to).push_back(s);
            }

            swap(next_cur, cur);
            next_cur->clear();
            swap(from, to);
            to->clear();

            depth++;
        }
        return 0;
    }
};

int main() {
    string beginWord, endWord;
    vector<string> wordList;
    int result;

    beginWord = "hit";
    endWord = "cog";
    wordList = {"hot","dot","dog","lot","log","cog"};
    result = Solution().ladderLength(beginWord, endWord, wordList);
    cout << result << endl;

}
