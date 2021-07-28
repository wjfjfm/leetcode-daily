#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
 private:
    struct Node {
        unordered_map<char, Node*> next;
        string end;
    };
    Node* tree;
    void add_node(string s) {
        Node* node = tree;
        for (char c : s) {
            if (node->next.count(c)) node = node->next[c];
            else {
                Node* n = new Node();
                node->next[c] = n;
                node = n;
            }
        }
        node->end = s;
    }
    vector<vector<bool>> visited;
    vector<string> result;
    vector<vector<char>>* board;
    int nx[4] = {0, 0, 1, -1};
    int ny[4] = {1, -1, 0, 0};
    int N, M;

    void find(int a, int b, Node* node) {
        if (!node->next.count((*board)[a][b])) return;
        node = node->next[(*board)[a][b]];
        if (node->end != "") {
            result.push_back(node->end);
            node->end = "";
        }
        visited[a][b] = true;
        for(int i=0; i<4; i++) {
            int x = a + nx[i];
            int y = b + ny[i];
            if (x < 0 || x >= N) continue;
            if (y < 0 || y >= M) continue;
            if (visited[x][y]) continue;
            find(x, y, node);
        }
        visited[a][b] = false;
    }


public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        tree = new Node();
        N = board.size();
        M = board[0].size();
        this->board = &board;
        visited = vector<vector<bool>>(N, vector<bool>(M, false));
        for(string s : words) {
            add_node(s);
        }
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                find(i, j, tree);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    vector<string> result;
    vector<vector<char>> board;
    vector<string> words;

    board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    words = {"oath","pea","eat","rain"};
    result = Solution().findWords(board, words);
    cout << result.size() << endl;
    for(string s : result) {
        cout << s << ' ';
    }
    cout << endl;
}
