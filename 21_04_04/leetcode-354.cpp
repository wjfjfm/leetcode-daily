#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int> c1, vector<int> c2){return c1[0] < c2[0] || (c1[0] == c2[0] && c1[1] < c2[1]);});
        // for (auto v: envelopes) {
        //     cout << v[0] << ' ' << v[1] << endl;
        // }
        vector<vector<int>> adv_env;
        int cur_i = -1;
        int cur_w = 0;
        for(auto v: envelopes) {
            if (v[0] > cur_w) {
                adv_env.push_back(vector<int>(0, 0));
                cur_w = v[0];
                cur_i++;
            }
            adv_env[cur_i].push_back(v[1]);
        }
        // // DEBUG
        // for (auto v: adv_env) {
        //     for( int i: v) {
        //         cout << i << ' ';
        //     }
        //     cout << endl;
        // }
        // // DEBUG
        const int N = adv_env.size();
        vector<pair<int, int>> dp[N];
        for (int i=0; i<N-1; i++) {
            dp[i].push_back(make_pair(adv_env[i][0], 1));
            sort(dp[i].begin(), dp[i].end(), [](pair<int, int> a, pair<int, int> b){return a.first < b.first || (a.first == b.first && a.second > b.second);});
            // // DEBUG
            // cout << "DEBUG: dp[" << i << "]: ";
            // for (auto p: dp[i]) {
            //     cout << p.first << ',' << p.second << "  ";
            // }
            // cout << endl;
            // // DEBUG
            int cur_h = 0;
            int cur_length = 0;
            for (auto p: dp[i]) {
                if (cur_h == p.first) continue;
                if (p.second <= cur_length) continue;
                cur_h = p.first;
                cur_length = p.second;
                dp[i+1].push_back(p);
                auto high_w_ptr = upper_bound(adv_env[i+1].begin(), adv_env[i+1].end(), cur_h);
                if (high_w_ptr != adv_env[i+1].end()){
                    dp[i+1].push_back(make_pair(*high_w_ptr, cur_length+1));
                }
            }
        }
        // // DEBUG
        // cout << "DEBUG: dp[" << N-1 << "]: ";
        // for (auto p: dp[N-1]) {
        //     cout << p.first << ',' << p.second << "  ";
        // }
        // cout << endl;
        // // DEBUG
        int result = 1;
        for (auto p: dp[N-1]) {
            result = max(result, p.second);
        }
        return result;

    }
};

int main() {
    vector<vector<int>> envelopes;
    int result;
    envelopes = {{5,4},{6,4},{6,7},{2,3}};
    result = Solution().maxEnvelopes(envelopes);
    cout << "result: " << result << endl << endl;
    envelopes = {{1,3},{3,5},{6,7},{6,8},{8,4},{9,5}};
    result = Solution().maxEnvelopes(envelopes);
    cout << "result: " << result << endl << endl;

}
