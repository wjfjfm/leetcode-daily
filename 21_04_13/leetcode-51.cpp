#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> answers;
    bool col[9], crow[18], rcow[18];
    vector<int> current;
    void search(const int r, const int n) {
        if (r == n-1) {
            for (int i = 0; i < n; i++) {
                if (!col[i] && !crow[r-i+n] && !rcow[r+i]) {
                    answers.push_back(current);
                    answers.back().push_back(i);
                }
            }
        }
        else for (int i = 0; i < n; i++) {
            if (!col[i] && !crow[r-i+n] && !rcow[r+i]) {
                current.push_back(i);
                col[i] = true;
                crow[r-i+n] = true;
                rcow[r+i] = true;

                search(r+1, n);

                current.pop_back();
                col[i] = false;
                crow[r-i+n] = false;
                rcow[r+i] = false;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        search(0, n);
        vector<vector<string>> result;
        string tmp = "";
        for(int i=0; i<n; i++) tmp = tmp + ".";
        for(auto v: answers) {
            vector<string> zero;
            result.push_back(zero);
            for(int i: v) {
                result.back().push_back(tmp);
                result.back().back()[i] = 'Q';
            }
        }
        return result;
    }
};


int main() {
    vector<vector<string>> result;
    result = Solution().solveNQueens(4);
    for(auto v: result) {
        for(string s: v) {
            cout << s << endl;
        }
        cout << endl;
    }

}
