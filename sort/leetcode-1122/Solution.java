import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

class Solution {
    private Map m_hashMap = new HashMap<Integer, Integer>();
    private ArrayList m_subList = new ArrayList<Integer>();

    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] result = new int[arr1.length];
        initValue(arr1, arr2);
        int[] temp = new int[m_subList.size()];
        for(int i = 0; i < m_subList.size(); i++) {
            temp[i] = (int)m_subList.get(i);
        }

        quickSort(temp, 0, temp.length - 1);

        int index = 0;
        for(int i = 0; i < arr2.length; i++) {
            Integer value = (Integer)m_hashMap.get(arr2[i]);
            for(int n = 0; n < value; n++) {
                result[index++] = arr2[i];
            }
        }

        int size = arr1.length - temp.length;
        for(int i = 0; i < temp.length; i++) {
            result[i + size] = temp[i];
        }

        return result;
    }

    private void initValue(int[] arr1, int[] arr2) {
        for(int i = 0; i < arr2.length; i++) {
            m_hashMap.put(arr2[i], 0);
        }

        for(int i = 0; i < arr1.length; i++) {
            if(true == m_hashMap.containsKey(Integer.valueOf(arr1[i]))) {
                Integer value = (Integer)m_hashMap.get(arr1[i]);
                m_hashMap.put(arr1[i], ++value);
            } else {
                m_subList.add(arr1[i]);
            }
        }
    }

    private void quickSort(int[] array, int start, int end) {
        if(start >= end) return;

        int left = start, right = end - 1;
        int swapTemp = 0;
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