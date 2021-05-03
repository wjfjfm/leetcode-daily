#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
    int times, val, index, step, key;
    Node(int key, int val) : key(key), val(val), times(1) {};
};

class LFUCache {
private:
    vector<Node*> stack;
    unordered_map<int, Node*> map;
    int cap;
    int step;
    bool built;

    inline bool Less(Node *A, Node *B) {
        if (A->times < B->times) return true;
        if (A->times > B->times) return false;
        if (A->step < B->step) return true;
        return false;
    }


    void update(int index) {
        if (!built) return;
        const int N = stack.size();
        int index_l = index * 2 + 1;
        int index_r = index_l + 1;
        while (index_l < N) {
            Node* m = stack[index];
            Node* l = stack[index_l];
            if (Less(l, m)) {
                if (index_r < N) {
                    Node* r = stack[index_r];
                    if (Less(r, l)) {
                        swap(stack[index], stack[index_r]);
                        stack[index]->index = index;
                        stack[index_r]->index = index_r;
                        index = index_r;
                        index_l = index * 2 + 1;
                        index_r = index_l + 1;
                    }
                    else{
                        swap(stack[index], stack[index_l]);
                        stack[index]->index = index;
                        stack[index_l]->index = index_l;
                        index = index_l;
                        index_l = index * 2 + 1;
                        index_r = index_l + 1;
                    }
                }
                else {
                    swap(stack[index], stack[index_l]);
                    stack[index]->index = index;
                    stack[index_l]->index = index_l;
                    index = index_l;
                    index_l = index * 2 + 1;
                    index_r = index_l + 1;
                }
            }
            else {
                if (index_r < N) {
                    Node* r = stack[index_r];
                    if (Less(r, m)) {
                        swap(stack[index], stack[index_r]);
                        stack[index]->index = index;
                        stack[index_r]->index = index_r;
                        index = index_r;
                        index_l = index * 2 + 1;
                        index_r = index_l + 1;
                    }
                    else return;
                }
                else return;
            }
        }
    }

    void build() {
        built = true;
        for (int i=(stack.size()-2)/2; i>=0; i--) {
            update(i);
        }
    }

    void print_stack() {
        for(auto n:stack) {
            cout << n->times << ' ';
        }
    }


public:
    LFUCache(int capacity) {
        cap = capacity;
        step = 0;
        built = false;
    }

    int get(int key) {
        step++;
        auto it = map.find(key);
        if (it != map.end()) {
            Node* node = it->second;
            node->step = step;
            node->times++;
            update(node->index);
            return map[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        step++;
        auto it = map.find(key);
        if (it != map.end()) {
            Node *node = it->second;
            node->step = step;
            node->times++;
            node->val = value;
            update(node->index);
        }
        else {
            if (stack.size() < cap) {
                Node* node = new Node(key, value);
                node->step = step;
                map[key] = node;
                node->index = stack.size();
                stack.push_back(node);
            }
            else {
                if (cap == 0) return;
                if (!built) build();
                Node* node = stack[0];
                node->step = step;
                map.erase(node->key);
                node->key = key;
                node->val = value;
                node->times = 1;
                map[key] = node;
                update(0);
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
