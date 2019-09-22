#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        vector<int> stackResult;
        cout << S.size() << endl;
        for(int i = 0; i < S.size(); i++) {
            vector<char> temp, stackVec;
            cout << "S[" << i << "]: " << S[i] << endl;
            temp.push_back(S[i]);
            if (')' ==  S[i]) {
                if (2 == temp.size()) {
                    temp.clear();
                    for(int n = 0; n < stackVec.size(); n++) {
                        stackResult.push_back(stackVec[n]);
                    }
                    stackVec.clear();
                } else {
                    stackVec.push_front(temp[temp.size()-2]);
                    stackVec.push_back(temp[temp.size()-1]);
                    temp.pop_back();
                    temp.pop_back();
                }
            }
        }

        string result;
        for(int i = 0; i < stackResult.size(); i++) {
            result.push_back(stackResult[i]);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution solution;
    string test = solution.removeOuterParentheses("(()())(())");
    cout << test.size() << endl;
    return 0;
}
