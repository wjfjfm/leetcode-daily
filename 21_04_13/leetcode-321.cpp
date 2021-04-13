#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

class mstack {
public:
    vector<int> stack;
    int num;
    mstack (int num) : num(num) {};
    void insert(const int n, const int top) {
        while(stack.size() > 0 && stack.back() < n && stack.size() > top) {
            stack.pop_back();
        }
        if(stack.size() < num) stack.push_back(n);
    }
};

class Solution {
private:
    static bool less(vector<int> &a, vector<int> &b) {
        for (int i=0; i<a.size(); i++) {
            if (a[i] < b[i]) return true;
            if (a[i] > b[i]) return false;
        }
        return false;
    }
    vector<int> search(const vector<int> &num1, const vector<int> &num2, int k, int l1, int l2) {
        int Max1, Max1_p, Max2, Max2_p;
        const int Ns1 = num1.size();
        const int Ns2 = num2.size();
        vector<int> result;
        for (int i=0; i<k; i++) {
            const int r1 = min(Ns1 + Ns2 - k - l2 + i + 1, Ns1);
            const int r2 = min(Ns1 + Ns2 - k - l1 + i + 1, Ns2);
            // cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << endl;
            Max1 = 0xcfcfcfcf;
            Max2 = 0xcfcfcfcf;

            for (int j = l1; j<r1; j++) {
                if (num1[j] > Max1) {
                    Max1 = num1[j];
                    Max1_p = j;
                }
            }
            for(int j=l2; j<r2; j++) {
                if (num2[j] > Max2) {
                    Max2 = num2[j];
                    Max2_p = j;
                }

            }
            if (Max1 == Max2) {
                // cout << "trigered! " << Max1 << endl;
                result.push_back(Max1);
                vector<int> result1 = search(num1, num2, k-i-1, Max1_p + 1, l2);
                vector<int> result2 = search(num1, num2, k-i-1, l1, Max2_p + 1);
                // cout << "result1: ";
                // for(int i: result1) cout << i << ' ';
                // cout << endl <<  "result2: ";
                // for(int i: result2) cout << i << ' ';
                // cout << endl;
                if (less(result1, result2)) {
                    for (int i:result2) result.push_back(i);
                }
                else for(int i:result1) result.push_back(i);
                return result;
            }
            else if (Max1 < Max2) {
                result.push_back(Max2);
                l2 = Max2_p + 1;
            }
            else {
                result.push_back(Max1);
                l1 = Max1_p + 1;
            }
        }
        return result;
    }
    vector<int> search2(vector<int> &num1, vector<int> &num2, int k) {
        vector<int> result;
        return result;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        mstack s1(k);
        mstack s2(k);
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        for (int i=0; i<N1; i++) {
            s1.insert(nums1[i], i-N1+k);
        }
        for (int i=0; i<N2; i++) {
            s2.insert(nums2[i], i-N2+k);
        }

        int Max, Max_p;
        bool Max_s;
        vector<int> result = search(s1.stack, s2.stack, k, 0, 0);

        return result;


    }
};

int main() {
    vector<int> nums1, nums2, result;
    int k;
    nums1 = {3, 4, 6, 5};
    nums2 = {9, 1, 2, 5, 8, 3};
    k = 5;
    result = Solution().maxNumber(nums1, nums2, k);
    for(int i: result) {
        cout << i << ' ';
    }
    cout << endl;

    nums1 = {6, 7};
    nums2 = {6, 0, 4};
    k = 5;
    result = Solution().maxNumber(nums1, nums2, k);
    for(int i: result) {
        cout << i << ' ';
    }
    cout << endl;

    nums1 = {3, 9};
    nums2 = {8, 9};
    k = 3;
    result = Solution().maxNumber(nums1, nums2, k);
    for(int i: result) {
        cout << i << ' ';
    }
    cout << endl;

    nums1 = {8, 9};
    nums2 = {3, 9};
    k = 3;
    result = Solution().maxNumber(nums1, nums2, k);
    for(int i: result) {
        cout << i << ' ';
    }
    cout << endl;
}
