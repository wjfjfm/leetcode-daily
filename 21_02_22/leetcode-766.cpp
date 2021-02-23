#include<vector>
using namespace std;
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int width = matrix[0].size();
        int height = matrix.size();
        for (int i=0; i<width-1; i++){
            for(int j=0; j<height-1; j++){
                if (matrix[j][i] != matrix[j+1][i+1]) return false;
            }
        }
        return true;
    }
};

int main(){
    vector<vector<int>> matrix = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    assert(Solution().isToeplitzMatrix(matrix) == true);
    matrix = {{1,2},{2,2}};
    assert(Solution().isToeplitzMatrix(matrix) == false);

}

