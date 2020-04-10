#include <vector>
#include <iostream>
#include "../../cclib/cclib-common/inc/util/util.h"

using namespace std;
using namespace cclib;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int temp = 0;
        int vectorSize = 0;
        for(int i = 0; i + vectorSize < nums.size() - 1; i++) {
            if(nums[i] == val) {
                if(nums[i+vectorSize+1] != val) {
                    temp = nums[i+vectorSize+1];
                    nums[i+vectorSize+1] = nums[i];
                    nums[i] = temp;
                } else {
                    vectorSize++;
                }
            }
        }
        cclib::common::util::printVectorValue(nums);
        for(int i = nums.size() - 1; i <= nums.size() - 1 && i > 0; i--) {
            if(nums[i] == val) {
                nums.pop_back();
                continue;
            }
            break;
        }

        return nums.size();
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution demo;
    vector<int> aaa{0,1,2,2,3,0,4,2};
    int res = demo.removeElement(aaa, 2);
    cout << res << endl;
    cclib::common::util::printVectorValue(aaa);
    return 0;
}
