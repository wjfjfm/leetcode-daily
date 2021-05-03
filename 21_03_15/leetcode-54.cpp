# include<iostream>
# include<vector>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        int delta[5][2] = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
        int next[5] = {1,2,3,0};
        int c_x = 0;
        int c_y = 0;
        int fail = 0;
        bool visited[12][12] = {};
        vector<int> result;
        int c_d = 0;
        int n_x = 0;
        int n_y = 0;
        int max_x = matrix.size();
        int max_y = matrix[0].size();
        while(fail < 4){
            if(n_x >=0 && n_y >=0 && n_x < max_x && n_y < max_y && visited[n_x][n_y] == 0){
                visited[n_x][n_y] = 1;
                fail = 0;
                result.push_back(matrix[n_x][n_y]);
                cout << matrix[n_x][n_y] << "available" << endl;
                c_x = n_x;
                c_y = n_y;
                n_x = c_x + delta[c_d][0];
                n_y = c_y + delta[c_d][1];
            }
            else{
                fail++;
                cout << n_x << ' ' << n_y << "NOT available" << endl;
                c_d = next[c_d];
                n_x = c_x + delta[c_d][0];
                n_y = c_y + delta[c_d][1];
            }
        }
        return result;

    }
};

int main(){
    vector<vector<int> > matrix = {{1,2,3},{4,5,6},{7,8,9}};
    auto result = Solution().spiralOrder(matrix);
    for (auto i:result){
        cout << i << ' ';
    }
    cout << endl;
}