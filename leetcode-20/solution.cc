#include <string>
#include "./../cclib/inc/adt/stack.h"
#include <stack>
#include <map>
#include <iostream>

using namespace cclib::adt;
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        Stack<char> expresstion;
        // stack<char> expresstion;
        expresstion.push('a');
        for(int i = 0; i < s.size(); i++) {
            if(validChar(s[i], expresstion.top())) {
                expresstion.pop();
                continue;
            }
            expresstion.push(s[i]);
        }

        return expresstion.size() == 1 ? true : false;
    }

    private:
    bool validChar(char word, char word1) {
        bool result = false;
        switch(word) {
            case ')': {
                result = '(' == word1;
                break;
            } case ']': {
                result = '[' == word1;
                break;
            } case '}': {
                result = '{' == word1;
                break;
            } default: {
                break;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution aa;
    bool bb = aa.isValid("()");
    cout << "bb: " << bb << endl;
    return 0;
}
