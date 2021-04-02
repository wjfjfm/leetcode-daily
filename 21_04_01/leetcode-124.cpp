/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int left, right;
        int result = -1e9;
        if (root->left != nullptr) {
            result = maxPathSum(root->left);
            left= root->left->val;
        }
        else
            left= 0;

        if (root->right !=nullptr) {
            right = maxPathSum(root->right);
            result = right > result ? right : result;
            right = root->right->val;
        }
        else
            right= 0;

        int max_child = left > right ? left : right;
        const int val = root->val;
        root->val += max_child > 0 ? max_child : 0;
        result = val > result ? val : result;
        result = val + left > result ? val + left : result;
        result = val + right > result ? val + right : result;
        result = val + left + right > result ? val + left + right : result;
        return result;
    }
};
