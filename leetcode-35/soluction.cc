#include <vector>
#include <iostream>
#include "./../cclib/cclib-common/inc/util/util.h"

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(NULL == (&nums)) {
            return -1;
        }

        return binarySearch(nums, 0, nums.size() - 1, target);
    }

private:
    int binarySearch(vector<int>& nums, int start, int end, int target) {
        if(start == end) {
            if (target > nums[start]) {
                vector<int>::iterator itr = nums.begin();
                nums.insert(itr + start + 1, target);
                return start + 1;
            } else if(target < nums[start]) {
                vector<int>::iterator itr = nums.begin();
                nums.insert(itr + start, target);
                return start;
            } else {
                return start;
            }
        }

        int middle = (end - start) / 2;

        //recursion
        if (target > nums[start + middle]) {
            return binarySearch(nums, start + middle + 1, end, target);
        } else if (target < nums[start + middle]) {
            return binarySearch(nums, start, start + middle, target);
        } else {
            return start + middle;
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution aa;
    vector<int> bb = {1, 3};
    int result = aa.searchInsert(bb, 0);

    cout << "result: " << result << endl;
    cclib::common::util::printVectorValue(bb);
    return 0;
}
