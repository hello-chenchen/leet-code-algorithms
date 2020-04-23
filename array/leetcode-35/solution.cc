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
    int binarySearch(vector<int>& nums, int target, int leftIndex, int rightIndex) {
        if(leftIndex > rightIndex) {
            return leftIndex;
        }
        int midIndex = (leftIndex + rightIndex) / 2;
        if(nums[midIndex] == target) {
            return midIndex;
        } else if(nums[midIndex] < target) {
            return binarySearch(nums, target, midIndex + 1, rightIndex);
        } else {
            return binarySearch(nums, target, leftIndex, midIndex - 1);
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> input{1,3,5,6};
    Solution solution;
    int result = solution.searchInsert(input, 2);
    cout << "result: " << result << endl;
    return 0;
}
