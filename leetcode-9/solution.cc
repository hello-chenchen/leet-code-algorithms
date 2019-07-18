//LINK:https://leetcode.com/problems/two-sum/
//COMPILE:g++ solution.cc -o main -std=c++11
#include <iostream>

using namespace std;

class Solution {
public:
    static bool isPalindrome(int x) {
        if(x < 0)
            return false;

        int* num = new int[1024];
        int index = 0;
        while(x >= 10) { //NOTICE: x > 10 && x < -10
            num[index++] = x % 10;
            x = x / 10; 
        }

        num[index] = x;
        int lastIndex = index;
        for(int i = 0; i < (index + 1) / 2; i++) {
            if(num[i] != num[lastIndex--]) {
                return false;
            }
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution::isPalindrome(10) << endl; 
    return 0;
}
