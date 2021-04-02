class Solution {
public:
    int trap(vector<int>& height) {
        vector<pair<int, int>> buffer;
        int floor, result = 0, current = 0;
        for (int h: height) {
            floor = 0;
            for (auto it = buffer.rbegin(); it != buffer.rend(); it++) {
                if (h >= (*it).first) {
                    result += ((*it).first - floor) * (current - (*it).second - 1);
                    floor = (*it).first;
                    buffer.pop_back();
                }
                else{
                    result += (h - floor) * (current - (*it).second - 1);
                    break;
                }
            }
            buffer.push_back(make_pair(h, current));
            current++;
        }
        return result;

    }
};
