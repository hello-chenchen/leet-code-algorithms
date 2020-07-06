#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() <= 1) {
            return;
        }
        for(int i = 0, k = 1; i < nums.size(); i++) {
            if(k >= nums.size()) {
                return;
            }
            if(0 == nums[i] && 0 != nums[k]) {
                swap(nums[i], nums[k++]);
                continue;
            } else if(0 != nums[i] && 0 != nums[k]) {
                k++;
            } else if(0 == nums[i] && 0 == nums[k]) {
                k++;
                i--;
            } else if(0 != nums[i] && 0 == nums[k]) {
                k++;
            }
        }
    }
};