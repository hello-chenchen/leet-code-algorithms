#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        nums.push_back(0);  //FIXED: leetcode AddressSanitizer: heap-buffer-overflow on address 0x602000000140 at
        int result = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            int temp = 0;
            while(1 == nums[i]) {
                temp++;
                i++;
            }

            result = temp > result ? temp : result;
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution cc;
    vector<int> a = {1,1,0,1};
    cout << cc.findMaxConsecutiveOnes(a);
    return 0;
}
