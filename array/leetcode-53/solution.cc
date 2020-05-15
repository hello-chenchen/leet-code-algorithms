#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(0 == nums.size()) {
            return numeric_limits<int>::min();
        }
        vector<int> max_num_group = {};

        int group_max = nums[0];
        int group_total = group_max;
        for(int i = 0; i < nums.size(); i++) {
            cout << group_max << " " << " " << nums[i] << endl;
            if(group_max <= 0) {
                group_max = group_max > nums[i] ? group_max : nums[i];
            } else {
                if(nums[i] < 0) {
                    group_total = group_max + nums[i];
                } else {

                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution cc;
    vector<int> aa = {-2,1,-3,4,-1,2,1,-5,4};
    int result = cc.maxSubArray(aa);
    cout << result << endl;
    return 0;
}
