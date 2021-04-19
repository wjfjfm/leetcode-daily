#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::unordered_map;
using std::max;


class Solution {
private:
    unordered_map<int, int> next;
    unordered_map<int, int> count;
    int max_len = 1;
    int find(int n) {
        auto it = next.find(n);
        if (it->second != n) {
            it->second = find(it->second);
        }
        return it->second;
    }
    void print_out() {
        cout << "next: " << endl;
        for(auto i:next) {
            cout << i.first << "\t->\t" << i.second  << "\t:\t" << count[i.first] << endl;
        }
        cout << endl;
    }
    void add_num(int n) {
        // cout << "DEBUG: " << n << endl;
        if (next.find(n) != next.end()) return;
        if (next.find(n+1) != next.end()){
            if (next.find(n-1) != next.end()) {
                const int l = find(n-1);
                next[n+1] = l;
                next[n] = l;
                count[l] += count[n+1] + 1;
                max_len = max(max_len, count[l]);
            }
            else {
                next[n+1] = n;
                next[n] = n;
                count[n] = count[n+1] + 1;
                max_len = max(max_len, count[n]);
            }
        }
        else {
            if (next.find(n-1) != next.end()) {
                const int l = find(n-1);
                next[n] = l;
                count[l] += 1;
                max_len = max(max_len, count[l]);
            }
            else {
                next[n] = n;
                count[n] = 1;
            }
        }

        // print_out();
    }
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        for(int i: nums) {
            add_num(i);
        }
        return max_len;
    }
};

int main() {
    vector<int> nums;
    int result;
    nums = {100,4,200,1,3,2};
    result = Solution().longestConsecutive(nums);
    cout << "result: " << result << endl;
    nums = {4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3};
    result = Solution().longestConsecutive(nums);
    cout << "result: " << result << endl;
}

