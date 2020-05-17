#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int size = digits.size() - 1;
        for(int i = size; i > 0; i--) {
            int num = ++digits[i];
            if(digits[i] < 9) {
                result.push_back(num);
            } else {
                vector<int> temp = splitVector(num);
                for(int n = 0; n < temp.size() - 1; n++) {
                    result.push_back(temp[n]);
                }
            }
        }

        vector<int> a;
        for(int i = result.size() - 1; i > 0; i--) {
            a.push_back(result[i]);
        }
        return a;
    }

private:
    vector<int> splitVector(int number) {
        vector<int> result;
        while (number >> 1) {
            result.push_back(number % 10);
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    vector<int> b({0,11,2});
    
    return 0;
}
