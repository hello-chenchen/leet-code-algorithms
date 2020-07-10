#include <vector>
#include <iostream>
#include "./../../cclib/cclib-common/inc/util/util.h"

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            // cout << "i: " << i << endl;
            while(nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) {
                // cout << "nums[" << i << "]: " << nums[i] << " i + 1: " << i + 1 << " nums[nums[i] - 1]: " << nums[nums[i] - 1] << endl; 
                swap(nums[i], nums[nums[i] - 1]);
            }

            // cout << "nums[" << i << "]: " << nums[i] << " nums[nums[i] - 1]: " << nums[nums[i] - 1] << endl; 
            if(nums[i] == nums[nums[i] - 1] && nums[i] != i + 1) {
                nums[i] = 0;
            }
            // cclib::common::util::printVectorValue(nums);
        }

        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            if(0 == nums[i]) {
                result.push_back(i + 1);
            }
        }

        // cout << "result: " << result.size() << endl;
        cclib::common::util::printVectorValue(result);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution aa;
    vector<int> b = {4,3,2,7,8,2,3,1};
    aa.findDisappearedNumbers(b);
    return 0;
}
