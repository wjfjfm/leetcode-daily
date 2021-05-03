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
        int lnum, rnum;
        while(cur) {
            lnum = cur->left ? cur->left->count : 0;
            rnum = cur->right ? cur->right->count : 0;
            if (lnum > 2 * rnum + 2) {
                Node* target = cur->left;
                Node* tmp = cur->right;
                int count = cur->count;
                swap(target->val, cur->val);
                cur->left = target->left;
                cur->right = target;
                target->left = target->right;
                target->right = tmp;
                target->count = count - target->count;
                target->count += target->left ? target->left->count : 0;
            }
            else if (rnum > 2 * lnum + 2) {
                Node* target = cur->right;
                Node* tmp = cur->left;
                int count = cur->count;
                swap(target->val, cur->val);
                cur->right = target->right;
                cur->left = target;
                target->right = target->left;
                target->left = tmp;
                target->count = count - target->count;
                target->count += target->right? target->right->count : 0;
            }
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
