#include <vector>
#include <map>
#include <iostream>
#include <set>
using namespace std;
class Solution {
private:
    bool check(vector<int> &jobs, vector<int> &inbag, int k, int bag, int i) {
        if (i == jobs.size()) return true;
        set<int> visited;
        for(int &j: inbag) {
            if (visited.count(j)) continue;
            visited.insert(j);
            if (j + jobs[i] <= bag) {
                j += jobs[i];
                if (check(jobs, inbag,  k, bag, i+1)) return true;
                j -= jobs[i];
            }
        }
        return false;
    }
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(), jobs.end());
        int l = 0;
        int r = 0;
        for(int i: jobs) r += i;
        while( l < r - 1) {
            int m = (l + r) >> 1;
            vector<int> inbag(k);
            if (check(jobs, inbag, k, m, 0)) {
                r = m;
            }
            else {
                l = m;
            }
        }
        return r;
    }
};

int main() {
    vector<int> jobs = {3, 2, 3};
    int k = 3;
    cout << Solution().minimumTimeRequired(jobs, k) << endl;

    jobs = {1, 2, 4, 7, 8};
    k = 2;
    cout << Solution().minimumTimeRequired(jobs, k) << endl;
}
