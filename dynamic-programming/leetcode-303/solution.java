class NumArray {
    private int[] m_nums = null;

    public NumArray(int[] nums) {
        if(null == nums || nums.length == 0) {
            return;
        }
        m_nums = new int[nums.length];
        m_nums[0] = nums[0];
        for(int i = 1; i < nums.length; i++) {
            m_nums[i] = m_nums[i-1] + nums[i];
        }
    }

    public int sumRange(int i, int j) {
        return m_nums[j] - (i == 0 ? 0 : m_nums[i-1]);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */