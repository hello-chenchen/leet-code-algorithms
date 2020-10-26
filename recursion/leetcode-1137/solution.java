class Solution {
    public int tribonacci(int n) {
        if(n <= 2) {
            return 0 == n ? 0 : 1;
        }
        int[] num = new int[n + 1];
        num[0] = 0;
        num[1] = 1;
        num[2] = 1;
        int sum = 0;
        for(int i = 0; i < n - 2; i++) {
            num[i + 3] = num[i] + num[i + 1] + num[i + 2];
            sum = num[i + 3];
        }

        return sum;
    }
}