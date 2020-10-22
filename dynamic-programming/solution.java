class Solution {
    public int climbStairs(int n) {
        int count = n / 2;
        int result = 0;
        for(int i = 0; i <= count; i++) {
            int count1 = n - i * 2;
            result += factorial(count1 + i) / factorial(count1) / factorial(i);
        }

        return result;
    }

    public long factorial(int number) {
        long result = 1;
        while(number > 1) {
            result *= number--;
        }

        return result;
    }
}