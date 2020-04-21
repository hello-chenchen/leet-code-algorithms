#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size());
    }

private:
    int binarySearch(vector<int>& nums, int target, int startIndex, int endIndex) {
        int midIndex = (endIndex - startIndex) / 2;
        if(nums[midIndex] > target) {
            // midIndex = (startIndex + midIndex) / 2;
            return binarySearch(nums, target, startIndex, midIndex);
        } else if(nums[midIndex] < target) {
            // midIndex = (midIndex + endIndex) / 2;
            return binarySearch(nums, target, midIndex, endIndex);
        } else {    //nums[midIndex] >= target
            return midIndex;
        }
    }
};