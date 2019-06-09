//LINK: https://leetcode.com/problems/reverse-integer/
//COMPILE: g++ solution.cc
//NOTICE: best solution
/***********************
 while(x) {
    res = res*10 + x%10;
    x /= 10;
}
***********************/
#include <iostream>
class Solution {
    public:
        int reverse(int x) {
            int* num = new int[1024];
            int index = 0;
            while(x <= -10 || x >= 10) {
                num[index++] = x % 10;
                x = x / 10;
            }

            long long y = x;
            int count = index;
            for(int i = 0; i < count; i++) {
                y = y + num[i] * pow(10, index--);
            }

            return ((y < INT_MIN) || (y > INT_MAX)) ? 0 : y;
        }

    private:
        inline long long pow(int x, int y) {
            if(y == 0) {
                return 1;
            }

            long long z = x;
            for(int i = 1; i < y; i++) {
                z = z * x;
            }

            return z;
        }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution test;
    int result = test.reverse(1534236469);
    std::cout << result << std::endl;
    return 0;
}
