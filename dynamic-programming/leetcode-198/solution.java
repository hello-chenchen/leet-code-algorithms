//NOTICE: f(x) = max(f(x-2) + num[x], f(x-1))
class Solution {
    public int rob(int[] nums) {
        if(null == nums || 0 ==nums.length) {
            return 0;
        }

        if(1 == nums.length) {
            return nums[0];
        }

        if(nums.length <= 2) {
            return nums[0] > nums[1] ? nums[0] : nums[1];
        }

        int result1 = nums[0];
        int result2 = nums[0] > nums[1] ? nums[0] : nums[1];
        int temp = 0;
        for(int i = 2; i < nums.length; i++) {
            temp = result1 + nums[i] > result2 ? result1 + nums[i] : result2;
            result1 = result2;
            result2 = temp;
        }

        return result2;
    }
}