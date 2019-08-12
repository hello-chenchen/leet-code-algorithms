#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        _M_val = new stack<int>();
    }

    ~MyQueue() {
        delete _M_val;
        _M_val = NULL;
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        _M_val->push(x);
        int start = 0;
        int end = _M_val->size();
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int result = _M_val->
    }

    /** Get the front element. */
    int peek() {

    }

    /** Returns whether the queue is empty. */
    bool empty() {

    }

private:
    stack<int>* _M_val;
};