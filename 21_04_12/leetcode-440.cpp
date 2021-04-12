#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        vector<int> tmp;

        int l = 0;
        int r = n + 1;
        while(n) {
            tmp.push_back(n % 10);
            n = n / 10;
        }
        vector<int> nums(tmp.rbegin(), tmp.rend());
        const int N = nums.size();

        vector<int> result;
        int status = 2;
        int depth = 0;
        vector<int> pow;
        int ti = 0;
        for(int i=0; i<=N; i++) {
            pow.push_back(ti);
            ti = ti * 10 + 1;
        }

        while(status) {
            switch(status){
            case 1:
                for(int i = 0; i < 10; i++) {
                    // cout << "<" << i << ' ';
                    const int count = pow[N - depth];
                    if (l + count < k) {
                        l = l + count;
                    }
                    else {
                        // cout << "! ";
                        result.push_back(i);
                        l += 1;
                        if (l == k) status = 0;
                        depth++;
                        break;
                    }

                }
                break;
            case 3:
                for(int i = 9; i >=0; i--) {
                    // cout << ">" << i << ' ';
                    const int count = pow[N - depth - 1];
                    if (r - count > k) {
                        r = r - count;
                    }
                    else {
                        // cout << "! ";
                        result.push_back(i);
                        if (r - count == k) status = 0;
                        depth++;
                        break;
                    }
                }
                break;
            case 2:
                for(int i = depth ? 0 : 1 ;i < nums[depth]; i++) {
                    // cout << "<" << i << ' ';
                    const int count = pow[N - depth];
                    if (l + count < k) {
                        l = l + count;
                    }
                    else {
                        // cout << "! ";
                        result.push_back(i);
                        l += 1;
                        if (l == k) status = 0;
                        else status = 1;
                        depth++;
                        break;
                    }
                }
                if (status == 2)
                for(int i = 9; i > nums[depth]; i--) {
                    // cout << ">" << i << ' ';
                    const int count = pow[N - depth - 1];
                    if (r - count > k) {
                        r = r - count;
                    }
                    else {
                        // cout << "! ";
                        // cout << r << ' ' << count << ' ' << k << endl;
                        result.push_back(i);
                        if (r - count == k) status = 0;
                        else status = 3;
                        depth++;
                        break;
                    }
                }
                if (status == 2) {
                    result.push_back(nums[depth]);
                    l += 1;
                    if (l == k) status = 0;
                    depth++;
                }

            }
        }
        int answer = 0;
        for(int i: result) {
            answer = 10 * answer + i;
        }
        return answer;
    }
};

int main() {
    int n, k, result;
    n = 13;
    k = 2;
    cout << "n = " << n << endl;
    result = Solution().findKthNumber(n, k);
    cout << endl << "result: ";
    cout << result << endl;

    n = 50;
    k = 25;
    cout << "n = " << n << endl;
    result = Solution().findKthNumber(n, k);
    cout << endl << "result: ";
    cout << result << endl;

    n = 11123;
    k = 2344;
    cout << "n = " << n << endl;
    result = Solution().findKthNumber(n, k);
    cout << endl << "result: ";
    cout << result << endl;

    n = 9123099;
    k = 345344;
    cout << "n = " << n << endl;
    result = Solution().findKthNumber(n, k);
    cout << endl << "result: ";
    cout << result << endl;

    n = 13;
    k = 2;
    cout << "n = " << n << endl;
    result = Solution().findKthNumber(n, k);
    cout << endl << "result: ";
    cout << result << endl;
}
