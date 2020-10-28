class Solution {
    public int largestPerimeter(int[] A) {
        quickSort(A, 0, A.length - 1);

    }

    private void quickSort(int[] array, int start, int end) {
        //array[end] is keyValue
        int swapTemp = 0;
        int left = start, right = end - 1;
        while(left < right) {
            if(array[left] > array[end] && array[right] < array[end]) {
                swapTemp = array[left];
                array[left] = array[right];
                array[right] = swapTemp;
                left++;
                right--;
            } else {
                if(array[left] < array[end]) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        if(array[left] < array[end]) {
            swapTemp = array[left];
            array[left] = array[end];
            array[end] = swapTemp;
        }

        quickSort(array, start, left - 1);
        quickSort(array, right + 1, end);
    }
}