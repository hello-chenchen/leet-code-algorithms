#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <list>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m[256]={0};//字符有256个
        int left=0;//查找的左边界
        int mlen=0;//结果
        for(int i = 0; i < s.length(); i++) {
            if(m[s[i]] == 0 || m[s[i]] < left) {
                mlen = max(mlen, i - left + 1);
            } else {
                left = m[s[i]];
            }
            m[s[i]] = i + 1;
        }

        return mlen;
    }
};

int main(int argc, char const *argv[])
{
    Solution aa;
    int b = aa.lengthOfLongestSubstring("pwwkew");
    std::cout << "b: " << b << std::endl;
    return 0;
}
