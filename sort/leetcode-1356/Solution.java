import java.util.ArrayList;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    private ArrayList<Integer>[] m_arrayList = new ArrayList[14];
    public int[] sortByBits(int[] arr) {
        int[] result = new int[arr.length];
        int temp = 0;
        for(int i = 0; i < arr.length; i++) {
            temp = containOneBinary(arr[i]);
            if(null != m_arrayList[temp]) {
                m_arrayList[temp].add(arr[i]);
            } else {
                m_arrayList[temp] = new ArrayList<Integer>();
                 m_arrayList[temp].add(arr[i]);
            }
        }

        int index = 0;
        for(int i = 0; i < m_arrayList.length; i++) {
            if(null != m_arrayList[i]) {
                quickSort(m_arrayList[i], 0, m_arrayList[i].size() - 1);
                for(Integer subItem : m_arrayList[i]) {
                    result[index++] = subItem;
                }
            }
        }

       return result;
    }

    private int containOneBinary(int decNum) {
        int result = 0;
        while(0 != decNum) {
            if(1 == (decNum & 0x0001)) {
                result++;
            }
            decNum = decNum >> 1;
        }

        return result;
    }

    private void quickSort(ArrayList<Integer> array, int start, int end) {
        if(start >= end) return;

        int left = start, right = end - 1;
        int swapTemp = 0;
        for(int i = left; i <= right; i++) {
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