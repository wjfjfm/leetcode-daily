class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        int m;
        int lnum = nums[0];
        int rnum = nums.back();
        int mnum;
        int min_to_max = 0xcfffffff;
        int max_to_min = 0x3fffffff;
        if (rnum == target) return true;
        while (lnum == rnum) {
            if (l + 1 < r) lnum = nums[++l];
            else return false;
        }
        if (lnum >= rnum ) {
            if ( lnum < target) {
                min_to_max = rnum;
            }
            else if (rnum > target) {
                max_to_min = lnum;
            }
            else if (lnum == target) return true;
            else if (rnum == target) return true;
            else return false;
        }
        if (lnum == rnum) {

        }
        while ( l < r) {
            m = (l + r) / 2;
            mnum = nums[m];
            if (mnum <= min_to_max) {
                mnum = 0x3fffffff;
            }
            else if (mnum >= max_to_min) {
                mnum = 0xcfffffff;
            }
            if (mnum < target) {
                l = m + 1;
            }
            else if (mnum > target) {
                r = m;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
