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
private:
    static void stack_down(vector<ListNode*> &stack, int p) {
        while(p >=0) {
            const int i0 = p;
            const int i1 = i0 * 2 + 1;
            const int i2 = i0 * 2 + 2;
            const int t0 =stack.size() > i0 ? (stack[i0] ? stack[i0]->val : 0xcfffffff) : 0x3fffffff;
            const int t1 = stack.size() > i1 ? (stack[i1] ? stack[i1]->val : 0xcfffffff) : 0x3fffffff;
            const int t2 = stack.size() > i2 ? (stack[i2] ? stack[i2]->val : 0xcfffffff)  : 0x3fffffff;
            if (t1 < t2 && t1 < t0) {
                swap(stack[i0], stack[i1]);
                p = i1;
            }
            else if(t2 <= t1 && t2 < t0) {
                swap(stack[i0], stack[i2]);
                p = i2;
            }
            else {
                p = -1;
            }
        }
    }
    static void pop_and_refresh(vector<ListNode*> &stack) {
        if (stack.size() == 0) return;
        if (stack[0] && stack[0]->next != nullptr) {
            stack[0] = stack[0]->next;
        }
        else {
            stack[0] = stack.back();
            stack.pop_back();
            if (stack.size() <= 1) return;
        }
        stack_down(stack, 0);
    }

    static void init_stack(vector<ListNode*> &stack) {
        for(int i=stack.size()-1; i>0; i--) {
            if (!stack[(i-1)/2]) continue;
            if (stack[i] == nullptr || stack[i]->val < stack[(i-1)/2]->val) {
                swap(stack[i], stack[(i-1)/2]);
                stack_down(stack, i);
            }
        }
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        init_stack(lists);
        ListNode* result = new ListNode();
        ListNode* it = result;

        while(true) {
            while(lists.size() > 0 && !lists[0]) pop_and_refresh(lists);
            if(lists.size() > 0) {
                it->next = lists[0];
                it = it->next;
                pop_and_refresh(lists);
            }
            else {
                break;
            }

        }
        return result->next;

    }
};
