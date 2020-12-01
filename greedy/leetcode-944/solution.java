class Solution {
    public int minDeletionSize(String[] A) {
        int result = 0;
        for(int i = 0; i < A[0].length(); i++) {
            char pre = A[0].charAt(i);
            for(int n = 1; n < A.length; n++) {
                if(pre <= A[n].charAt(i)) {
                    pre = A[n].charAt(i);
                } else {
                    result++;
                    break;
                }
            }
        }

        return result;
    }
}