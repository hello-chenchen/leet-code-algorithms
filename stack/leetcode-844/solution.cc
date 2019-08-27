#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        vector<char> stackS, stackT;
        backspace(S, stackS);
        backspace(T, stackT);

        if(stackS.size() != stackT.size()) {
            return false;
        }
        
        for(int i = 0; i < stackS.size(); i++) {
            if(stackS[i] != stackT[i]) {
                return false;
            }
        }

        return true;
    }

private:
    void backspace(string value, vector<char>& stackS) {
        for(int i = 0; i < value.size(); i++) {
            if(value.at(i) == '#') {
                if(stackS.size()) {
                    stackS.pop_back();
                }
            } else {
                stackS.push_back(value.at(i));
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    string S = "gtc#uz#";
    string T = "gtc#uz##";
    Solution sol;
    bool result = sol.backspaceCompare(S,T);
    cout << result << endl;
    return 0;
}
