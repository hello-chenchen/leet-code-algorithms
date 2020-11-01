import java.lang.reflect.Array;
import java.util.ArrayList;
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

        Iterator iter = m_hashMap.entrySet().iterator();
        while (iter.hasNext()) {
            Map.Entry entry = (Map.Entry) iter.next();
            Integer key = (Integer)entry.getKey();
            Integer value = (Integer)entry.getValue();
            for(int i = 0; i < value; i++) {
                result[i] = key;
            }
        }

        int hashSize = m_hashMap.size();
        for(int i = 0; i < temp.length; i++) {
            result[i + hashSize] = temp[i];
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
                m_hashMap.put(arr1[i], value++);
            }
        }

        Iterator iter = m_hashMap.entrySet().iterator();
        while (iter.hasNext()) {
            Map.Entry entry = (Map.Entry) iter.next();
            Integer val = (Integer)entry.getValue();
            if(0 == val) {
                m_subList.add((Integer)entry.getKey());
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