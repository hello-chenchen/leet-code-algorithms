#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        _M_push = new stack<int>();
        _M_pop = new stack<int>();
    }

    ~MyQueue() {
        delete _M_push;
        _M_push = NULL;

        delete _M_pop;
        _M_pop = NULL;
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        _M_push->push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(_M_pop->empty()) {
            while(!_M_push->empty()) {
                _M_pop->push(_M_push->top());
                _M_push->pop();
            }
        }

        int result = _M_pop->top();
        _M_pop->pop();
        return result;
    }

    /** Get the front element. */
    int peek() {
        if(_M_pop->empty()) {
            while(!_M_push->empty()) {
                _M_pop->push(_M_push->top());
                _M_push->pop();
            }
        }

        return _M_pop->top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return _M_push->empty() && _M_pop->empty();
    }

private:
    stack<int>* _M_push;
    stack<int>* _M_pop;
};