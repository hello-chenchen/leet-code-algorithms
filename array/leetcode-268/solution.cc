#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sumNumber = (0 + nums.size()) * (nums.size() + 1) / 2;
        for(int i = 0; i < nums.size(); i++) {
            sumNumber = sumNumber - nums[i];
        }

        return sumNumber;
    }
};