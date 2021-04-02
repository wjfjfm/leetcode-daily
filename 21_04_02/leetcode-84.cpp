class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        vector<pair<int,int> > stack;
        int current = 0;
        int result = 0;
        for (int h: heights) {
            int position = current;
            for(auto it = stack.rbegin(); it != stack.rend(); it++) {
                if ((*it).first >= h) {
                    const int tmp = (*it).first * (current - (*it).second);
                    result = tmp > result ? tmp : result;
                    position = (*it).second;
                    stack.pop_back();
                }
            }
            stack.push_back(make_pair(h, position));
            current++;
        }
        return result;
    }
};
