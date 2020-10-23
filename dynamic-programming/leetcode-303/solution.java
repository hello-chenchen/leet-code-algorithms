class NumArray {

    private int[] m_nums = null;

    public NumArray(int[] nums) {
        m_nums = nums;
    }

    public int sumRange(int i, int j) {
        int result = 0;
        for(; i <= j; i++) {
            result += m_nums[i];
        }

        return result;
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */