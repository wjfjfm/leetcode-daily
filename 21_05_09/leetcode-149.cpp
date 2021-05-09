#include <math.h>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        map<pair<long long, long long>, int> map;
        long long a, b;
        for(auto it1 = points.begin(); it1 != points.end(); it1++) {
            for(auto it2 = it1+1; it2 != points.end(); it2++) {
                if ((it2->at(0) - it1->at(0)) == 0) {
                    a = 0x7fffffff;
                    b = it1->at(0);
                }
                else {
                    a = (long long)(it2->at(1) - it1->at(1)) * 100000 / (it2->at(0) - it1->at(0));
                    b = (long long)it1->at(1) * 100000 - (long long)(it2->at(1) - it1->at(1)) * it1->at(0) * 100000 / (it2->at(0) - it1->at(0));
                }
                map[make_pair(a, b)]++;
            }
        }
        int count = 0;
        for(auto p: map) {
            count = count < p.second ? p.second : count;
        }

        return (int)sqrt(2 * count) + 1;

    }
};

int main() {
    vector<vector<int>> points;

    points = {{1,1},{2,2},{3,3}};
    cout << Solution().maxPoints(points) << endl;
}
