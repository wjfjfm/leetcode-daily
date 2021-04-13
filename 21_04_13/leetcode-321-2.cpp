#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

class mstack {
public:
    vector<int> stack;
    int n;
    vector<vector<int>*> nums;
    mstack (const int n, int nl,  const vector<int> &num) : n(n) {
        nl = nl < 0 ? 0 : nl;
        const int N = num.size();
        nums.resize(N+1);
        for(int i=0; i<N-n; i++) {
            while(stack.size() > 0 && stack.back() < num[i]) {
                stack.pop_back();
            }
            if(stack.size() < n) stack.push_back(num[i]);
        }
        int cur_bar = min(n, N);
        for(int i=max(0, N-n); i<N; i++) {
            while(stack.size() > 0 && stack.back() < num[i]) {
                if (cur_bar - stack.size() >= N - i) {
                    nums[cur_bar] = new vector<int>(stack.begin(), stack.end());
                    for(int j=i; j<N; j++) {
                        nums[cur_bar]->push_back(num[j]);
                    }
                    cur_bar--;
                    if (cur_bar < nl) return;
                }
                stack.pop_back();
            }
            if(stack.size() < cur_bar) stack.push_back(num[i]);
        }
        for(int i=nl; i <= cur_bar; i++) {
            nums[i] = &stack;
        }
    };
};

class Solution {
private:
    static bool less(const vector<int> &a, const vector<int> &b) {
        for (int i=0; i<a.size(); i++) {
            if (a[i] < b[i]) return true;
            if (a[i] > b[i]) return false;
        }
        return false;
    }
    vector<int> search(const vector<int> &num1, const vector<int> &num2, int k, const vector<vector<int>*> &ms1, const vector<vector<int>*> &ms2) {
        vector<int> result(k);
        for(int i=0; i<=k; i++) {
            if (num1.size() < i || num2.size() < k-i) continue;
            // cout << "Debug: i = " << i << endl;
            vector<int> nums1 = *ms1[i];
            vector<int> nums2 = *ms2[k-i];
            int p1=0, p2=0;
            bool write_in = false;
            for(int j=0; j<k; j++) {
                int select;
                // cout << "DEBUG: i j k p1 p2 " << i<<' '<<j<<' '<<k<<' '<<p1<<' '<<p2<<endl;
                // cout << "DEBUG: nums1.size nums2.size " << nums1.size() << ' ' << nums2.size() << endl;
                if(p2 >= k-i ) select = 1;
                else if (p1 >= i) select = 2;
                else if (nums1[p1] > nums2[p2]) select = 1;
                else if (nums1[p1] < nums2[p2]) select = 2;
                else if (p2 + 1 >= k-i) select = 1;
                else if (p1 + 1 >= i) select = 2;
                else if (nums1[p1 + 1] > nums2[p2 + 1]) select = 1;
                else if (nums1[p1 + 1] < nums2[p2 + 1]) select = 2;
                else {
                    int pp1 = p1 + 2;
                    int pp2 = p2 + 2;
                    while(true){
                        if(pp2 >=k-i) select = 1;
                        else if (pp1 >= i) select  = 2;
                        else if (nums1[pp1] > nums2[pp2]) select = 1;
                        else if (nums1[pp1] < nums2[pp2]) select = 2;
                        else {
                            pp1++;
                            pp2++;
                            continue;
                        }
                        break;
                    }
                }


                if(select == 1) {
                    // cout << "select s1[" << p1 << "] = " << nums1[p1] << endl;
                    if (write_in) result[j] = nums1[p1];
                    else if (nums1[p1] < result[j]) break;
                    else if (nums1[p1] > result[j]) {
                        result[j] = nums1[p1];
                        write_in = true;
                    }
                    p1++;
                }
                else {
                    // cout << "select s2[" << p2 << "] = " << nums2[p2] << endl;
                    if (write_in) result[j] = nums2[p2];
                    else if (nums2[p2] < result[j]) break;
                    else if (nums2[p2] > result[j]) {
                        result[j] = nums2[p2];
                        write_in = true;
                    }
                    p2++;
                }
            }
        }
        return result;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        mstack s1(k, k - nums2.size(), nums1);
        mstack s2(k, k - nums1.size(), nums2);
        // cout << "s1: " << endl;
        // cout << "stack: ";
        // for(int i: s1.stack) cout << i << ' ';
        // cout << endl;
        // for (int i=1; i<=min(k, (int)nums1.size()); i++) {
        //     cout << "nums[" << i << "]: ";
        //     for(int j: *(s1.nums)[i]) cout << j << ' ';
        //     cout << endl;
        // }
        // cout << "s2: " << endl;
        // cout << "stack: ";
        // for(int i: s2.stack) cout << i << ' ';
        // cout << endl;
        // for (int i=1; i<=min(k, (int)nums2.size()); i++) {
        //     cout << "nums[" << i << "]: ";
        //     for(int j: *(s2.nums)[i]) cout << j << ' ';
        //     cout << endl;
        // }

        vector<int> result = search(nums1, nums2, k, s1.nums, s2.nums);

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

    nums1 = {1,6,5,4,7,3,9,5,3,7,8,4,1,1,4};
    nums2 = {4,3,1,3,5,9};
    k = 21;
    result = Solution().maxNumber(nums1, nums2, k);
    for(int i: result) {
        cout << i << ' ';
    }
    cout << endl;

    nums1 = {3,8,5,3,4};
    nums2 = {8,7,3,6,8};
    k = 5;
    result = Solution().maxNumber(nums1, nums2, k);
    for(int i: result) {
        cout << i << ' ';
    }
    cout << endl;

    nums1 = {2,1,7,8,0,1,7,3,5,8,9,0,0,7,0,2,2,7,3,5,5};
    nums2 = {2,6,2,0,1,0,5,4,5,5,3,3,3,4};
    k =35;
    result = Solution().maxNumber(nums1, nums2, k);
    for(int i: result) {
        cout << i << ' ';
    }
    cout << endl;

    nums1 = {5,0,2,1,0,1,0,3,9,1,2,8,0,9,8,1,4,7,3};
    nums2 = {7,6,7,1,0,1,0,5,6,0,5,0};
    k = 31;
    result = Solution().maxNumber(nums1, nums2, k);
    for(int i: result) {
        cout << i << ' ';
    }
    cout << endl;
}
