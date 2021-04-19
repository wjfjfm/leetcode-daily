#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

class Solution {
private:
    short iboard[9][9];
    bitset<9> col[9], row[9], block[9];
    void print_iboard(int sr = -1, int sc = -1) {

        for (int r=0; r<9; r++) {
            if (r % 3 == 0) {
                for (int i=0; i<19; i++) {
                    cout << '-';
                }
                cout << endl;
            }
            for (int c=0; c<9; c++) {
                if (r == sr && c == sc) cout << '*';
                else if (c % 3 == 0) cout << '|';
                else cout << ' ';
                cout << iboard[r][c] + 1;
                if (r == sr && c == sc) cout << '*';
                else if (c == 8) cout << '|';
            }
            cout << endl;
            if (r == 8) {
                for (int i=0; i<19; i++) {
                    cout << '-';
                }
                cout << endl;
            }
        }
    }
    void print_bitset(bitset<9> bs[9]) {
        for( int j=0; j<9; j++){
            for(int i=0; i<9; i++) {
                if (bs[j][i]) cout << i + 1;
                else cout << 'x';
            }
            cout << endl;
        }
    }
    void print_status(int r = -1, int c = -1) {
        print_iboard(r, c);
        cout << "col:" << endl;
        print_bitset(col);
        cout << "row:" << endl;
        print_bitset(row);
        cout << "block:" << endl;
        print_bitset(block);

    }
    bool trytry(const int bi, const int index) {
        if (bi > 8) return true;
        const int r = bi / 3 * 3 + index / 3;
        const int c = bi % 3 * 3 + index % 3;
        if (iboard[r][c] >= 0)
            return trytry(bi + (index + 1) / 9, (index + 1) % 9);
        bitset<9> exist = col[c] | row[r] | block[bi];
        for (int i=0; i<9; i++) {
            if (exist[i]) continue;
            iboard[r][c] = i;
            col[c][i] = 1;
            row[r][i] = 1;
            block[bi][i] = 1;
            if (trytry(bi + (index + 1) / 9, (index + 1) % 9))
                return true;
            col[c][i] = 0;
            row[r][i] = 0;
            block[bi][i] = 0;
        }
        iboard[r][c] = -1;
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if (board[i][j] == '.') iboard[i][j] = -1;
                else {
                    const int tmp = board[i][j] - '1';
                    iboard[i][j] = tmp;
                    col[j][tmp] = 1;
                    row[i][tmp] = 1;
                    block[i / 3 * 3 + j / 3][tmp] = 1;
                }
            }
        }
        trytry(0, 0);
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                board[i][j] = iboard[i][j] + '1';
            }
        }
    }
};

void print_board(const vector<vector<char>>& board) {
    int c = 0, r = 0;

    for (auto v: board) {
        if (r % 3 == 0) {
            for (int i=0; i<19; i++) {
                cout << '-';
            }
            cout << endl;
        }
        for (auto i: v) {
            if (c % 3 == 0) cout << '|';
            else cout << ' ';
            cout << i;
            if (c == 8) cout << '|';
            c = (c + 1) % 9;
        }
        cout << endl;
        if (r == 8) {
            for (int i=0; i<19; i++) {
                cout << '-';
            }
            cout << endl;
        }
        r = r + 1;
    }
}

int main() {
        vector<vector<char>>  board = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
        };
        print_board(board);
        Solution().solveSudoku(board);
        print_board(board);
}
