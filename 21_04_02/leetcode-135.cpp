class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();
        vector<int> next[N];
        int pri_num[N];
        memset(pri_num, 0, N * sizeof(int));

        for (size_t i=1; i<N; i++) {
            if (ratings[i] > ratings[i-1]){
                next[i-1].push_back(i);
                pri_num[i]++;
            }
            else if (ratings[i] < ratings[i-1]) {
                next[i].push_back(i-1);
                pri_num[i-1]++;
            }
        }

        vector<int> t0, t1;
        for (int i=0; i<N; i++) {
            if (pri_num[i] == 0) {
                t0.push_back(i);
            }
        }

        int candy = 1;
        int result = 0;
        while (t0.size() > 0) {
            for (int i: t0) {
                result += candy;
                for(int j: next[i]) {
                    pri_num[j]--;
                    if (pri_num[j] == 0) {
                        t1.push_back(j);
                    }
                }
            }
            t0.clear();
            swap(t0, t1);
            candy++;
        }
        return result;
    }
};
