#include <string>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> result;

        for(int i = 0; i < S.size(); i++) {
            if(result.size() != 0) {
            }
            if(result.size() == 0 || result.top() != S[i]) {
                result.push(S[i]);
            } else {
                result.pop();
            }
        }

        string strResult = "";
        int a = result.size();
        for(int i = 0; i < a; i++) {
            strResult.push_back(result.top());
            result.pop();
        }

        reverse(strResult.begin(),strResult.end());
        return strResult;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    Solution solution;
    string test = solution.removeDuplicates("abbaca");
    cout << test << endl;
    return 0;
}