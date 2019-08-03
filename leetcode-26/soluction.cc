// #include "./../cclib/inc/adt/vector.h"
#include <vector>
#include "./../cclib/cclib-common/inc/util/util.h"

using namespace cclib;
// using namespace cclib::adt;
using namespace cclib::common::util;
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) {
            return nums.size();
        }

        int temp = nums[0];
        vector<int>::iterator itr = nums.begin() + 1;
        int size = nums.size();
        while(itr != nums.end()) {
            vector<int>::iterator tmp = itr;
            if(temp == *itr) {
                nums.erase(itr);
            } else {
                temp = *itr;
                itr++;
            }
        }
        return nums.size();
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> aa = {0,0,1,1,1,2,2,3,3,4};
    Solution bb;
    int cc = bb.removeDuplicates(aa);
    cout << cc << endl;
    printVectorValue(aa);
    return 0;
}
