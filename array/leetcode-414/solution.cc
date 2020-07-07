#include <vector>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> topThree = {-1, -1, -1};
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > topThree[0]) {
                swap(nums[i], topThree[0]);
                sort(topThree);
            }
        }
        return topThree[0] >= 0 ? topThree[0] : topThree[2];
    }

private:
    void sort(vector<int>& nums) {
        if(nums[0] > nums[2]) {
            swap(nums[0], nums[1]);
            swap(nums[1], nums[2]);
        } else if(nums[0] > nums[1] && nums[0] < nums[2]) {
            swap(nums[0], nums[1]);
        }
    }
};