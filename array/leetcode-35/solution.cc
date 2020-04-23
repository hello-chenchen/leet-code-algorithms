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

        while(midIndex > startIndex) {
            if(nums[midIndex] > target) {
                endIndex = midIndex;
            } else if(nums[midIndex] < target) {
                startIndex = midIndex;
            } else {
                return midIndex;
            }
            midIndex = (endIndex + startIndex) / 2;
        }

        if(target <= nums[startIndex]) {
            return startIndex;
        } else if(target > nums[endIndex]) {
            return endIndex + 1;
        } else {
            return startIndex + 1;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> input{1,3,5,6};
    Solution solution;
    int result = solution.searchInsert(input, 0);
    cout << "result: " << result << endl;
    return 0;
}
