#include <deque>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        _M_val = new deque<int>();
    }

    ~MyStack() {
        delete _M_val;
        _M_val = NULL;
    }

    /** Push element x onto stack. */
    void push(int x) {
        _M_val->push_back(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int result = _M_val->back();
        _M_val->pop_back();
        return result;
    }

    /** Get the top element. */
    int top() {
        return _M_val->back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return 0 == _M_val->size();
    }

private:
    deque<int>* _M_val;
};
