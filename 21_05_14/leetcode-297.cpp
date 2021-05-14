#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string result = "";
        if (root->left) result += "(" + serialize(root->left) + ")";
        result += to_string(root->val);
        if (root->right) result += "(" + serialize(root->right) + ")";
        return result;
    }

    inline int parseInt(const string &data, int &ptr) {
        int x = 0, sgn = 1;
        if(!isdigit(data[ptr])) {
            sgn = -1;
            ++ptr;
        }
        while(isdigit(data[ptr])) {
            x = x * 10 + data[ptr++] - '0';
        }
        return x * sgn;
    }

    TreeNode* parse(const string &data, int &ptr) {
        if (data[ptr] == ')') return nullptr;
        auto cur = new TreeNode(0);
        if (data[ptr] == '(') {
            ++ptr;
            cur->left = parse(data, ptr);
            ++ptr;
        }
        cur->val = parseInt(data, ptr);
        if (ptr < data.size() && data[ptr] == '(') {
            ++ptr;
            cur->right = parse(data, ptr);
            ++ptr;
        }
        return cur;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return nullptr;
        int ptr = 0;
        return parse(data, ptr);
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
