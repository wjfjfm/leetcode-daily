#include<cstdio>
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int num = 0;
        int length = A.size();
        vector<bool> result;
        for(int i=0; i<length; i++){
            num = ((num << 1) + A[i]) % 5;
            result.emplace_back(num  ==0);
        }
        return result;
    }
};



