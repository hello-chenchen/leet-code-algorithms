#include <vector>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> topThree = {numeric_limits<int>::min(), numeric_limits<int>::min(), numeric_limits<int>::min()};
        int flag = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == numeric_limits<int>::min()) {
                flag++;
                continue;
            }
            if(nums[i] > topThree[0] && nums[i] != topThree[1] && nums[i] != topThree[2]) {
                swap(nums[i], topThree[0]);
                sort(topThree);
            }
        }

        if(flag > 0) {
            if(topThree[0] == topThree[1] && topThree[0] == numeric_limits<int>::min()) {
                return topThree[2];
            } else if(topThree[0] == numeric_limits<int>::min()){
                return topThree[0];
            }
        }

        return topThree[0] > numeric_limits<int>::min() ? topThree[0] : topThree[2];
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