#include <queue>
#include <iostream>
#include <vector>
using namespace std;

class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> q2;
    priority_queue<int> q1;

public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        if (q1.size() == 0) q1.push(num);
        else if (num < q1.top()) q1.push(num);
        else if (q2.size() == 0) q2.push(num);
        else if (num > q2.top()) q2.push(num);
        else if (q1.size() == q2.size()) q1.push(num);
        else q2.push(num);

        while(q1.size() < q2.size()) {
            q1.push(q2.top());
            q2.pop();
        }

        while(q2.size() < q1.size() - 1) {
            q2.push(q1.top());
            q1.pop();
        }
    }

    double findMedian() {
        if (q1.size() == q2.size()) return (double)(q1.top() + q2.top()) / 2.0;
        else return q1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    MedianFinder *mf = new MedianFinder();
    mf->addNum(1);
    mf->addNum(2);
    cout << mf->findMedian() << ' ';
    mf->addNum(3);
    cout << mf->findMedian() << ' ';
    cout << endl;
    delete mf;
}
