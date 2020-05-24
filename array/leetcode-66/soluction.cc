#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        return callBackPlus(digits, digits.size() - 1);
    }

private:
    vector<int> callBackPlus(vector<int>& digits, int index) {
        while (digits[index] == 9 && index != 0) {
            digits[index] = 0;
            index--;
        }

        if(digits[index] < 9) {
            digits[index] = digits[index] + 1;
        } else if(0 == index) {
            digits[index] = 0;
            std::vector<int>::iterator it;
            it = digits.begin();
            it = digits.insert (it , 1);
        }

        return digits;
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    vector<int> b({0,11,2});

    return 0;
}
