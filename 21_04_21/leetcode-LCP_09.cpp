#include <deque>
#include <vector>
#include <iostream>
#include <assert.h>
#include <memory>
#include <cstring>
using namespace std;

class Solution {
public:
    int minJump(vector<int>& jump) {
        const int N = jump.size();
        bool visited[N];
        memset(visited, 0, N * sizeof(bool));
        unique_ptr<vector<int>> cur(new vector<int>());
        unique_ptr<vector<int>> next(new vector<int>());
        int back = 1;
        int cur_jump = 0;
        int jump_to;
        cur->push_back(0);
        while(true) {
            cur_jump++;
            for(int i: *cur) {
                jump_to = jump[i] + i;
                if (jump_to >= N) return cur_jump;
                if (!visited[jump_to]) {
                    visited[jump_to] = true;
                    next->push_back(jump_to);
                }
                if (i > back) {
                    for(int j=back; j<i; j++) {
                        if (visited[j]) continue;
                        visited[j] = true;
                        next->push_back(j);
                    }
                    back = i + 1;
                }
            }
            swap(next, cur);
            next->clear();

        }
        assert(false);
        return 0;
    }
};

int main() {
    vector<int> jump;
    int result;
    jump = {2, 5, 1, 1, 1, 1};
    result = Solution().minJump(jump);
    cout << result << endl;
    jump = {4,6,10,8,3,5,3,5,7,8,6,10,3,7,3,10,7,10,10,9,1,4,7,4,8,6,9,8,8,2,7,2,4,5,4,3,3,2,2,2,3,4,4,1,1,5,6,8,1,2};
    result = Solution().minJump(jump);
    cout << result << endl;
}
