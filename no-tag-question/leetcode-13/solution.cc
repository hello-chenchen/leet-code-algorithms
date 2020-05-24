//LINK: https://leetcode-cn.com/problems/roman-to-integer/
//COMPILE:g++ two-sum/solution.cc -o tmp/main -std=c++11
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for(int i = 0; i < s.size(); i++) {
            switch(s[i]) {
                case 'M': {
                    result += 1000;
                    break;
                } case 'D': {
                    result += 500;
                    break;
                } case 'C': {
                    switch(s[++i]) {
                        case 'D': {
                            result += 400;
                            break;
                        } case 'M': {
                            result += 900;
                            break;
                        } default: {
                            result += 100;
                            --i;
                            break;
                        }
                    }
                    break;
                } case 'L': {
                    result += 50;
                    break;
                } case 'X': {
                    switch(s[++i]) {
                        case 'L': {
                            result += 40;
                            break;
                        } case 'C': {
                            result += 90;
                            break;
                        } default: {
                            result += 10;
                            --i;
                            break;
                        }
                    }
                    break;
                } case 'V': {
                    result += 5;
                    break;
                } case 'I': {
                    switch(s[++i]) {
                        case 'V': {
                            result += 4;
                            break;
                        } case 'X': {
                            result += 9;
                            break;
                        } default: {
                            result += 1;
                            --i;
                            break;
                        }
                    }
                    break;
                } default: {
                    return 0;
                }
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution aa;
    int bb = aa.romanToInt("MCMXCIV");
    cout << "bb: " << bb << endl;
    return 0;
}
