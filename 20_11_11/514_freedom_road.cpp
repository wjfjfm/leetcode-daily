#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        const int MAX = 1e9;
        int dp[110][110];
        int Nr = ring.size();
        int Nk = key.size();
        
        for(int i=0; i<Nk; i++){
            for(int j=0; j<Nr; j++){
                dp[i][j] = MAX;
            }
        }
        
        return 10;
    }
    

};

int main(){
    Solution solution;
    cout << solution.findRotateSteps("ring", "key"); 
}

