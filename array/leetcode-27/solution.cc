#include <vector>
#include <iostream>
#include "../../cclib/cclib-common/inc/util/util.h"

using namespace std;
using namespace cclib;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) {
            return 0;
        }

        int index = nums.size() - 1;

        for(int i = nums.size() - 1; i >= 0; i--) {
            if(val == nums[i]) {
                if(index != i) {
                    std::swap(nums[i], nums[index]);
                }
                index--;
            }
        }

        // cclib::common::util::printVectorValue(nums);
        return ++index;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution demo;
    vector<int> aaa{0,1,2,2,3,0,4,2};
    int res = demo.removeElement(aaa, 2);
    cout << res << endl;
    return 0;
}
