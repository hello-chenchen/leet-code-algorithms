class Solution {
    public int largestPerimeter(int[] A) {
        quickSort(A, 0, A.length - 1);

        for(int i = A.length - 3; i >= 0; i--) {
            if(A[i] + A[i+1] > A[i+2]) {
                return A[i] + A[i+1] + A[i+2];
            }
        }

        return 0;
    }

    private void quickSort(int[] array, int start, int end) {
        if(start >= end) return;

        //array[end] is keyValue
        int swapTemp = 0;
        int left = start, right = end - 1;
        for(int i = left; i <= right; i++) {
            if(array[i] <= array[end]) {
                swapTemp = array[left];
                array[left] = array[i];
                array[i] = swapTemp;
                left++;
            }
        }

        swapTemp = array[left];
        array[left] = array[end];
        array[end] = swapTemp;

        quickSort(array, start, left - 1);
        quickSort(array, left + 1, end);
    }
}