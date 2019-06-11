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
        while(s.size() > 0) {
            string firstChars = s.substr(0, 2);
            int twoChars = convert2Word(firstChars);
            if(0 == twoChars) {
                string firstChar = s.substr(0, 1);
                twoChars = convert1Word(firstChar);
                if(0 == twoChars) {
                    return 0;
                } else {
                    s.replace(0, 1, "");
                }
            } else {
                s.replace(0, 2, "");
            }

            result += twoChars;
        }

        if(result < 1 || result > 3999) {
            return 0;
        }

        return result;
    }

private:
    int convert2Word(string word) {
        if(word.size() < 2) {
            return 0;
        }

        map<string, int> Roman2Words({ {"IV", 4}, {"IX", 9},
            {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900} });

        map<string, int>::iterator itr = Roman2Words.find(word);
        if(itr != Roman2Words.end()) {
            return itr->second;
        } else {
            return 0;
        }
    }

    int convert1Word(string word) {
        if(word.size() < 1) {
            return 0;
        }

        map<string, int> Roman1Words({ {"I", 1}, {"V", 5}, {"X", 10},
            {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000} });

        map<string, int>::iterator itr = Roman1Words.find(word);
        if(itr != Roman1Words.end()) {
            return itr->second;
        } else {
            return 0;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution aa;
    int bb = aa.romanToInt("CMaI");
    cout << "bb: " << bb << endl;
    return 0;
}
