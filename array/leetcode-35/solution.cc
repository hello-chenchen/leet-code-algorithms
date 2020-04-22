#include <vector>
#include <iostream>
#include "../../cclib/cclib-common/inc/util/util.h"

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }

private:
    int binarySearch(vector<int>& nums, int target, int startIndex, int endIndex) {
        int midIndex = (endIndex + startIndex) / 2;
        if(startIndex == midIndex) {
            if(target <= nums[startIndex]) {
                return startIndex;
            } else if(target > nums[endIndex]) {
                return endIndex + 1;
            } else {
                return startIndex + 1;
            }
        }

        if(nums[midIndex] > target) {
            return binarySearch(nums, target, startIndex, midIndex);
        } else if(nums[midIndex] < target) {
            return binarySearch(nums, target, midIndex, endIndex);
        } else {
            return midIndex;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> input{1};
    Solution solution;
    int result = solution.searchInsert(input, 1);
    cout << "result: " << result << endl;
    return 0;
}
