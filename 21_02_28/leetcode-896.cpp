#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int previous = A[0];
        int judge = 0;
        for (auto num: A){
            if ((num - previous) * judge < 0) return false;
            if (judge == 0) judge = num - previous;
            previous = num;
        }
        return true;
    }
};

int main(){
    vector<int> A = {1,2,2,3};
    bool result = true;
    assert(Solution().isMonotonic(A) == result);

    A = {6,5,4,4};
    result = true;
    assert(Solution().isMonotonic(A) == result);

    A = {1,3,2};
    result = false;
    assert(Solution().isMonotonic(A) == result);

    cout << "Test PASS!" << endl;

}
