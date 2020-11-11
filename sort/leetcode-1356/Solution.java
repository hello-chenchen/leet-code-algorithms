import java.util.ArrayList;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    private HashMap<Integer,ArrayList<Integer>> m_list = new HashMap<Integer,ArrayList<Integer>>();
    public int[] sortByBits(int[] arr) {
        int temp = 0;
        for(int i = 0; i < arr.length; i++) {
            temp = containOneBinary(arr[i]);
            if(true == m_list.containsKey(temp)) {
                m_list.get(temp).add(arr[i]);
            } else {
                m_list.put(temp, new ArrayList<Integer>(arr[i]));
            }
        }

        quickSort();
    }

    private int containOneBinary(int decNum) {
        int result = 0;
        while(0 != decNum) {
            if(decNum != (decNum & 0xffff)) {
                result++;
                decNum = decNum >> 1;
            }
        }

        return result;
    }

    private void quickSort(int[] array, int start, int end) {
        int left = start, right = end - 1;
        int swapTemp = 0;
        for(int i = left; i < right; i++) {
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