//NOTICE: f(x) = min(f(x-2) + num[x-1], f(x-1) + num[x])
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int result1 = 0;    //NOTICE:
        int result2 = cost[0] < cost[1] ? cost[0] : cost[1];
        int result = 0, temp1 = 0, temp2 = 0;
        for(int i = 2; i < cost.length; i++) {
            temp1 = result1 + cost[i - 1];
            temp2 = result2 + cost[i];
            result = temp1 < temp2 ? temp1 : temp2;
            result1 = result2;
            result2 = result;
        }

        return result;
    }
}