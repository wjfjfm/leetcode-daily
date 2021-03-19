#include <vector>
#include <string>
using namespace std;
typedef struct {
    char value;
    bool mm;
} node;

class Solution {
private:
    bool isMatchSub(vector<char> s, vector<node> p, int i_s, int i_p, bool stat[32][32]);

public:
    bool isMatch(string s, string p) {
        vector<node> nodes;
        vector<char> chars(s.begin(), s.end());
        bool stat[32][32];
        for (int i=0; i<32; i++){
            for(int j=0; j<32; j++){
                stat[i][j] = false;
            }
        }
        for(char c:p){
            if (c != '*') {
                node tmp_node = node();
                tmp_node.value = c;
                tmp_node.mm = false;
                nodes.push_back(tmp_node);
            }
            else
                nodes.back().mm = true;
        }
        return isMatchSub(chars, nodes, 0, 0, stat);
    }

};
bool Solution::isMatchSub(vector<char> s, vector<node> p, int i_s, int i_p, bool stat[32][32]) {
    if (stat[i_s][i_p]){
        return false;
    }
    stat[i_s][i_p] = true;
    if (i_s == s.size() || i_p == p.size()) {
        if (i_s == s.size() && i_p == p.size()) return true;
        if (i_s == s.size()) {
            for(int i=i_p; i<p.size(); i++)
                if (!p[i].mm) return false;
            return true;
        }
        return false;
    }
    if (p[i_p].mm) {
        if (isMatchSub(s, p, i_s, i_p + 1, stat)) return true;
        if (p[i_p].value == '.' || s[i_s] == p[i_p].value) {
            return isMatchSub(s, p, i_s + 1, i_p, stat);
        }
    }
    else{
        if (p[i_p].value == '.' || s[i_s] == p[i_p].value) {
            return isMatchSub(s, p, i_s + 1, i_p + 1, stat);
        }
    }
    return false;
}

int main(){
    return 0;
}

