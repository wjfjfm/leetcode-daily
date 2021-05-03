#include <vector>
#include <iostream>
using namespace std;

struct Node {
    int val;
    int count;
    Node *left, *right;
    Node(int val) : val(val), count(1), left(nullptr), right(nullptr) {};
};
class Solution {
private:
    Node* root = nullptr;
    int insert(int val) {
        if(!root) {
            root = new Node(val);
            return 0;
        }
        Node* cur = root;
        int result = 0;
        while(cur) {
            if (cur->val < val) {
                result += cur->count;
                cur->count++;
                if (cur->right) {
                    result -= cur->right->count;
                    cur = cur->right;
                }
                else {
                    cur->right = new Node(val);
                    break;
                }
            }
            else if(cur->val > val) {
                cur->count++;
                if (cur->left) cur = cur->left;
                else {
                    cur->left = new Node(val);
                    break;
                }
            }
            else {
                if(cur->left) result += cur->left->count;
                cur->count++;
                break;
            }
        }
        return result;

    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        Node* root = new Node(0);
        vector<int> result;
        for(auto it=nums.rbegin(); it!=nums.rend(); it++) {
            result.push_back(insert(*it));
        }
        result = vector<int>(result.rbegin(), result.rend());
        return result;

    }
};

int main() {
    vector<int> result, nums;
    nums = {5, 2, 6, 1};
    result = Solution().countSmaller(nums);
    for(int i: result) cout << i << ' ';
    cout << endl;
}
