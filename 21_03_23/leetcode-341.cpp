#include<iostream>
#include <vector>
using namespace std;


class NestedIterator {
private:
    vector<int> results;
    vector<int>::iterator cur;

    void dfs(const vector<NestedInteger> &nestedList) {
        for (auto &nest : nestedList) {
            if (nest.isInteger()) {
                results.push_back(nest.getInteger());
            }
            else {
                dfs(nest.getList());
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
       dfs(nestedList);
       cur = results.begin();
    }

    int next() {
        return *cur++;
    }

    bool hasNext() {
        return cur != result.end();
    }
};
