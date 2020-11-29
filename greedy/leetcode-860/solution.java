class Solution {
    public boolean lemonadeChange(int[] bills) {
        int[] fiveResult = new int[2];
        for(int i = 0; i < bills.length; i++) {
            if(5 == bills[i]) {
                fiveResult[0]++;
            } else if(10 == bills[i]) {
                if(fiveResult[0] > 0) {
                    fiveResult[0]--;
                    fiveResult[1]++;
                } else {
                    return false;
                }
            } else {
                if(fiveResult[0] > 0 && fiveResult[1] > 0) {
                    fiveResult[0]--;
                    fiveResult[1]--;
                } else if(fiveResult[0] > 2) {
                    fiveResult[0] = fiveResult[0] - 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
}