#include <vector>
#include "./../cclib/cclib-common/inc/util/util.h"

using namespace std;
using namespace cclib::common::util;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
       for(int i = 0; i < nums1.size(); i++) {
           vector<int> temp;
           for(int n = nums2.size() - 1; n >= 0; n--) {
               if(nums2[n] == nums1[i]) {
                   int value = 0 == temp.size() ? -1 : temp.back();
                   result.push_back(value);
                   break;
               } else if(nums2[n] > nums1[i]) {
                    temp.push_back(nums2[n]);
               }
           }
       }

       return result;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    Solution solution;
    vector<int> result = solution.nextGreaterElement(nums1, nums2);
    printVectorValue(result);
    return 0;
}
