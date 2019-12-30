#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        if(S.size() <= 2) {
            return "";
        }
        int leftIndex = 1;
        int rightIndex = 0;
        string ret = "";
        for(int i = 1; i < S.size(); i++) {
            if(S[i] == '(') {
                leftIndex++;
            } else {
                rightIndex++;
            }
            if(leftIndex == rightIndex) {
                i++;
                leftIndex = 1;
                rightIndex = 0;
            } else {
                ret += S[i];
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution solution;
    string test = solution.removeOuterParentheses("(()())(())");
    cout << test << endl;
    return 0;
}
