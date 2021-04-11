#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> que;
        que.push(1L);
        int num = 1;
        while (num < n) {
            num++;
            const long now = que.top();
            que.pop();
            que.push(now * 5);
            if (now % 5 == 0) continue;
            que.push(now * 3);
            if (now % 3 == 0) continue;
            que.push(now * 2);
        }
        return (int)que.top();
    }
};

int main() {
    cout << Solution().nthUglyNumber(10) << endl;
    cout << Solution().nthUglyNumber(13) << endl;
}

