#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int result = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= target) {
                result = i;
                break;
            } else {
                result = i + 1;
            }
        }
        return result;
    }
};