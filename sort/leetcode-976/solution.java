class Solution {
    public int largestPerimeter(int[] A) {
        quickSort(A, 0, A.length - 1);

    }

    private void quickSort(int[] array, int start, int end) {
        int index = end;
        int key = array[index];
        int swapTemp = 0;
        int left = start, right = end - 1;
        while(left <= right) {
            if(array[left] > key && array[right] < key) {
                swapTemp = array[left];
                array[left] = array[right];
                array[right] = swapTemp;
                left++;
                right--;
            } else {
                if(array[left] < key) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        quickSort(array, start, left - 1);
        quickSort(array, right + 1, end);
    }
}