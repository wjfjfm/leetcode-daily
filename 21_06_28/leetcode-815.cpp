#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using ::std::unordered_map;
using ::std::unordered_set;
using ::std::vector;
using ::std::cout;
using ::std::endl;

class Solution {
 public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        const int N = routes.size();
        vector<int> cur, next;
        vector<unordered_set<int>> next_to(N);
        unordered_map<int, vector<int>> map;
        vector<bool> is_target(N);
        vector<bool> visited(N);

        for (int i = 0; i < routes.size(); i++) {
            for (int st : routes[i]) {
                if (st == source) {
                    visited[i] = true;
                    if (is_target[i]) return 1;
                    cur.push_back(i);
                }
                if (st == target) {
                    is_target[i] = true;
                    if (visited[i]) return 1;
                }
                for (int j : map[st]) {
                    next_to[i].insert(j);
                    next_to[j].insert(i);
                }
                map[st].push_back(i);
            }
        }

        int result = 1;
        while (cur.size() > 0) {
            result++;
            for (int i : cur) {
                for (int j : next_to[i]) {
                    if (visited[j]) continue;
                    visited[j] = true;
                    if (is_target[j]) return result;
                    next.push_back(j);
                }
            }
            cur.clear();
            swap(next, cur);
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> routes;
    int source, target, result;

    routes = {{1, 2, 7},{3, 6, 7}};
    source = 1;
    target = 6;
    result = Solution().numBusesToDestination(routes, source, target);
    cout << result << endl;

    routes = {{7,12},{4,5,15},{6},{15,19},{9,12,13}};
    source = 15;
    target = 12;
    result = Solution().numBusesToDestination(routes, source, target);
    cout << result << endl;
}
