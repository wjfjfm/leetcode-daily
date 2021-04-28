#include <vector>
#include <unordered_map>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class RandomizedCollection {
private:
    vector<pair<int, bool>> vec;
    vector<int> zero;
    unordered_map<int, vector<int>> place;

public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand((unsigned) time(0));

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if (zero.size() == 0) {
            place[val].push_back(vec.size());
            vec.push_back(make_pair(val, true));
        }
        else {
            const int tmp = zero.back();
            zero.pop_back();
            vec[tmp].first = val;
            vec[tmp].second = true;
            place[val].push_back(tmp);
        }
        if (place[val].size() == 1) return true;
        return false;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (place.count(val) && place[val].size() > 0) {
            int tmp = place[val].back();
            place[val].pop_back();
            zero.push_back(tmp);
            vec[tmp].second = false;
            return true;
        }
        else return false;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        unsigned int index = rand() % vec.size();
        if (vec[index].second) return vec[index].first;
        else return getRandom();
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    RandomizedCollection *rc = new RandomizedCollection();
    cout << rc->insert(1);
    cout << rc->remove(1);
    cout << rc->insert(1);
    cout << rc->getRandom();
    delete rc;
}
