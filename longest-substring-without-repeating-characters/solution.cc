#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() < 2) {
            return s.size();
        }
        int result = 1;
        for(int i = s.size()-1; i >= 0; i--) {
            cout << "i: " << i << endl;
            for(int n = i-1; n >= 0; n--) {
                cout << "n: " << n << " s[" << i << "]: "
                << s[i] << " s[" << n << "]: " << s[n] << endl;
                if(s[i] != s[n]) {
                    int num = i - n + 1;
                    cout << "num: " << num << " result: " << result << endl;
                    if(num > result) {
                        // cout << "result1: " << result << endl;
                        result = num;
                    }
                } else {
                    break;
                }
            }
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution aa;
    int b = aa.lengthOfLongestSubstring("pwwkew");
    std::cout << "b: " << b << std::endl;
    return 0;
}
