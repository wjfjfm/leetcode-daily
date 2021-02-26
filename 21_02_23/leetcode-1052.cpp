#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int already = 0;
        for(int i=0; i<customers.size(); i++){
            already += customers[i] * ( 1 - grumpy[i] );
            customers[i] = customers[i] * grumpy[i];
        }
        int save = 0;
        for(int i=0; i<X; i++){
            save += customers[i];
        }
        int max_save = save;
        for(int i=X; i<customers.size(); i++){
            save += customers[i];
            save -= customers[i-X];
            max_save = std::max(save, max_save);
        }
        return ( already + save );
    }
};


int main(){
    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy = {0,1,0,1,0,1,0,1};
    int X = 3;
    assert(Solution().maxSatisfied(customers, grumpy, X) == 16);
    cout << "Test PASS!" << endl;
}
