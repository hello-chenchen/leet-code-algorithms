#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    struct Status {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUP(Status left, Status right) {
        int iSum = left.iSum + right.iSum;
        int lSum = max(left.lSum, left.iSum + right.lSum);
        int rSum = max(right.rSum, left.rSum + right.iSum);
        int mSum = max(max(left.mSum, right.mSum), left.rSum + right.lSum);

        return (Status) {lSum, rSum, mSum, iSum};
    }

    Status get(vector<int> &nums, int left, int right) {
        if(left == right) {
            return (Status) {nums[left], nums[left], nums[left], nums[left]};
        }

        int middle = (left + right) >> 1;
        Status leftStatus = get(nums, left, middle);
        Status rightStatus = get(nums, middle + 1, right);
        return pushUP(leftStatus, rightStatus);
    }

    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};

int main(int argc, char const *argv[])
{
    Solution cc;
    vector<int> aa = {-2,1,-3,4,-1,2,1,-5,4};
    int result = cc.maxSubArray(aa);
    cout << result << endl;
    return 0;
}
