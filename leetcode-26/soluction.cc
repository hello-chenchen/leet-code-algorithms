#include "./../cclib/inc/adt/vector.h"
#include "./../cclib/cclib-common/inc/util/util.h"

using namespace cclib;
using namespace cclib::adt;
using namespace cclib::common::util;
// using namespace std;

class Solution {
public:
    int removeDuplicates(Vector<int>& nums) {
        int loop = 1, diff = 0;
        int size = nums.size();

        //O(n)
        for(; loop < size; loop++) {
            if(nums[loop] != nums[diff]) {
                nums[++diff] = nums[loop];
            }
        }

        //O(n)
        for(int i = nums.size() - 1; i > diff; i--) {
            nums.pop_back();
        }

        return nums.size();
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Vector<int> aa = {0,0,1,1,1,2,2,3,3,4};
    Solution bb;
    int cc = bb.removeDuplicates(aa);
    printVectorValue(aa);
    return 0;
}
