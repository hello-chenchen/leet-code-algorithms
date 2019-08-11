#include <vector>
#include <iostream>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        _M_val = new vector<int>();
        _M_min_val = new vector<int>();
    }

    ~MinStack() {
        delete _M_val;
        _M_val = NULL;

        delete _M_min_val;
        _M_min_val = NULL;
    }

    void push(int x) {

        if(0 == _M_val->size()) {
            _M_min_val->push_back(x);
        } else{
            int minTop = _M_min_val->at(_M_min_val->size() - 1);
            if(x < minTop) {
            _M_min_val->push_back(x);
            } else {
                _M_min_val->push_back(minTop);
            }
        }

        _M_val->push_back(x);
    }

    void pop() {
        _M_val->pop_back();
        _M_min_val->pop_back();
    }

    int top() {
        return _M_val->at(_M_val->size() - 1);
    }

    int getMin() {
        return _M_min_val->at(_M_min_val->size() - 1);
    }

private:
    vector<int>* _M_val;
    vector<int>* _M_min_val;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char const *argv[])
{
    /* code */
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-1);
    // minStack.pop();

    // int a = minStack.getMin();
    // int b = minStack.top();
    // cout << a << endl;
    // cout << b << endl;
    // vector<int>* aa = new vector<int>();
    // cout << aa->size() << endl;
    return 0;
}
