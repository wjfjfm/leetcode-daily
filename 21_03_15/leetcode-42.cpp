# include<vector>
# include<iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<pair<int, int> > stack;
        int position = -1;
        int current = 0;
        for(int h: height){
            int tmp = 0;
            position++;
            for(int i=stack.size()-1; i>=0; i--){
                if(stack[i].first <= h){
                    current += (stack[i].first - tmp) * (position - stack[i].second - 1);
                    stack.pop_back();
                    tmp = stack[i].first;
                }
            }
            stack.push_back(make_pair(h, position));
        }
        return current;
    }
};