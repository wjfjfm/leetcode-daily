#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    pair<TreeNode*, TreeNode*> check(TreeNode* node, TreeNode* minv, TreeNode* maxv) {
        if (!node) return make_pair(nullptr, nullptr);
        if ((!maxv || node->val <= maxv->val) && (!minv || node->val >= minv->val)) {
            auto l = check(node->left, minv, node);
            auto r = check(node->right, node, maxv);
            if (l.first && r.first) return make_pair(l.first, r.first);
            else if (l.first) return l;
            else return r;
        }
        else {
            if (maxv && node->val > maxv->val) {
                auto l = check(node->left, minv, node);
                if (l.first) return make_pair(l.first, maxv);
                else return make_pair(node, maxv);
            }
            else {
                auto r = check(node->right, node, maxv);
                if (r.first) return make_pair(r.first, minv);
                else return make_pair(node, minv);
            }
        }
    }
public:
    void recoverTree(TreeNode* root) {
        auto nodes = check(root, nullptr, nullptr);
            swap(nodes.first->val, nodes.second->val);
    }
};
