class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int left = 0, right = A.length - 1, swapTemp = 0;
        while(left < right) {
            if(isMatch(A[left], left) && isMatch(A[right], right)) {
                left++;
                right--;
            } else if(!isMatch(A[left], left) && isMatch(A[right], right)) {
                right--;
            } else if(isMatch(A[left], left) && !isMatch(A[right], right)) {
                left++;
            } else {
                if(!isMatch(A[left], A[right])) {
                    swapTemp = A[left];
                    A[left] = A[right];
                    A[right] = swapTemp;
                    left++;
                    right--;
                } else {
                    for(int i = left + 1; i < right; i++) {
                        if(!isMatch(A[left], A[i])) {
                            swapTemp = A[i];
                            A[i] = A[left];
                            A[left] = swapTemp;
                            left++;
                            break;
                        }
                    }

                    for(int i = right - 1; i > left; i--) {
                        if(!isMatch(A[i], A[right])) {
                            swapTemp = A[i];
                            A[i] = A[right];
                            A[right] = swapTemp;
                            right--;
                            break;
                        }
                    }
                }
            }
        }

        return A;
    }

    private boolean isMatch(int index, int value) {
        return (index % 2) == (value % 2) ? true : false;
    }
}