#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()) return "";
        string result = "";
        int vectorSize = strs.size();
        int minSize = strs[0].size();
        for(int i =1; i < vectorSize; i++) {
            int strSize = strs[i].size();
            minSize = minSize < strSize ? minSize : strSize;
        }

        for(int index = 0; index < minSize; index++) {
            for(int i = 0; i < vectorSize-1; i++) {
                if(strs[i][index] != strs[i+1][index]) {
                    return result;
                }
            }
            result += strs[0][index];
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    vector<string> bb;
    // bb.push_back("aaa1234");
    // bb.push_back("aaa2134");
    // bb.push_back("aaa3123");
    Solution aa;
    string c = aa.longestCommonPrefix(bb);
    cout << c << endl;
    return 0;
}
