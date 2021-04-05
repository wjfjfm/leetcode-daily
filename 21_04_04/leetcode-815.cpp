#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        const int N = routes.size();
        unordered_map<int, unordered_set<int>> next_to;
        unordered_set<int> has_station[N];
        int route = 0;
        for (auto v: routes) {
            for (int i: v) {
                has_station[route].insert(i);
            }
            route++;
        }
        for (int from=0; from<N; from++){
            for (int to=from+1; to<N; to++) {
                for (int i: routes[from]) {
                    if (has_station[to].count(i)) {
                        next_to[from].insert(to);
                        next_to[to].insert(from);
                        break;
                    }
                }
            }
            if (has_station[from].count(source)) {
                next_to[from].insert(N);
                next_to[N].insert(from);
            }
            if (has_station[from].count(target)) {
                next_to[from].insert(N+1);
                next_to[N+1].insert(from);
            }
        }
        source = N;
        target = N+1;
        unordered_set<int> cur_s, cur_t, visited_s, visited_t, next_s, next_t;
        int length = 0;
        cur_s.insert(source);
        cur_t.insert(target);
        visited_s.insert(source);
        visited_t.insert(target);
        while(true) {
            if ((length & 1) == 0){
                for(int i: cur_s) {
                    for(int j: next_to[i]) {
                        if (visited_s.count(j)) continue;
                        if (visited_t.count(j)) return length;
                        visited_s.insert(j);
                        next_s.insert(j);
                    }
                }
                if(next_s.size() == 0) break;
                cur_s.clear();
                swap(next_s, cur_s);
            }
            else {
                for(int i: cur_t) {
                    for (int j: next_to[i]) {
                        if (visited_t.count(j)) continue;
                        if (visited_s.count(j)) return length;
                        visited_t.insert(j);
                        next_t.insert(j);
                    }
                }
                if(next_t.size() == 0) break;
                cur_t.clear();
                swap(next_t, cur_t);
            }
            length++;
        }
        return -1;

        // for(auto p: next_to) {
        //     cout << p.first << ": ";
        //     for(int i: p.second) {
        //         cout << i << ' ';
        //     }
        //     cout << endl;
        // }
    }
};


int main() {
    vector<vector<int>> routes;
    int source, target, result;
    routes = {{1,2,7}, {3,6,7}};
    source = 1;
    target = 6;
    result = Solution().numBusesToDestination(routes, source, target);
    cout << result << endl;

}
