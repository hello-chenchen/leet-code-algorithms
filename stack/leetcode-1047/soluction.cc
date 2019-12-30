#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        string result = "";

        for(int i = 0; i < S.size(); i++) {
            if(result.size() == 0 || *(--result.end()) != S[i]) {
                result.push_back(S[i]);
            } else {
                result.pop_back();
            }
        }

        return result;
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