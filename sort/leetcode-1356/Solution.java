import java.util.ArrayList;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    private ArrayList<ArrayList<Integer>> m_arrayList = new ArrayList<ArrayList<Integer>>(14);
    public int[] sortByBits(int[] arr) {
        int[] result = new int[arr.length];
        int temp = 0;
        for(int i = 0; i < arr.length; i++) {
            temp = containOneBinary(arr[i]);
            if(null == m_arrayList.get(temp)) {
                m_arrayList.get(temp).add(arr[i]);
            } else {
                m_arrayList.set(temp, new ArrayList<Integer>(arr[i]));
            }
        }

        int index = 0;
        for (ArrayList<Integer> item : m_arrayList) {
            if(null != item) {
                quickSort(item, 0, item.size() - 1);
                for(Integer subItem : item) {
                    result[index++] = subItem;
                }
            }
       }

       return result;
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

    private void quickSort(ArrayList<Integer> array, int start, int end) {
        int left = start, right = end - 1;
        int swapTemp = 0;
        for(int i = left; i < right; i++) {
            if(array.get(i) <= array.get(end)) {
                swapTemp = array.get(left);
                array.set(left, array.get(i));
                array.set(i, swapTemp);
                left++;
            }
        }

        swapTemp = array.get(left);
        array.set(left, array.get(end));
        array.set(end, swapTemp);

        quickSort(array, start, left - 1);
        quickSort(array, left + 1, end);
    }
}