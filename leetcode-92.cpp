/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* node_0, node_1, node_2, node_3, node_00;
        ListNode* fake_head = new ListNode(0, head);
        node_0 = fake_head;
        for(int i=1; i<left; i++){
            node_0 = node_0 -> next;
        }
        node_1 = node_0 ? node_0 -> next : nullptr;
        node_2 = node_1 ? node_1 -> next : nullptr;
        node_3 = node_2 ? node_2 -> next : nullptr;
        node_00 = node_1;
        for (int i=left; i<right; i++){
            node_2 -> next = node_1;
            node_1 = node_2;
            node_2 = node_3;
            node_3 = node_3 ? node_3 -> next : nullptr;
        }
        node_0 -> next = node_1;
        node_1 -> next = node_2;
        return fake_head -> next;
    }
};
