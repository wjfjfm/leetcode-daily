#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return head;
        vector<ListNode*> tmp;
        ListNode* cur = head;
        tmp.push_back(head);
        for (int i=1; i<k; i++) {
            cur = cur->next;
            if (cur == nullptr) return head;
            tmp.push_back(cur);
        }
        cur = cur->next;
        for (int i=k-1; i>0; i--) {
            tmp[i]->next = tmp[i-1];
        }
        tmp[0]->next = reverseKGroup(cur, k);
        return tmp[k-1];
    }
};

int main() {
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(1, node1);
    ListNode *result = Solution().reverseKGroup(node2, 2);
    while(result != nullptr) {
        cout << result->val << ' ';
        result = result->next;
    }
    return 0;
}
