class Solution {
public:
    int longestValidParentheses(string s) {
        vector<pair<int,int>> stack;
        int position = 0;
        int current = 0;
        int result = 0;
        for (char c: s) {
            if (c == '(') {
                stack.push_back(make_pair(position, current));
                current = 0;
            }
            else {
                if (stack.size() > 0) {
                    current = position - stack.back().first + 1 + stack.back().second;
                    stack.pop_back();
                    result = current > result ? current : result;
                }
                else {
                    current = 0;
                }
            }
            position++;
        }
        return result;
    }
};
