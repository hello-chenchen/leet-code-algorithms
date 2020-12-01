import java.util.ArrayList;

class Solution {
    public int largestSumAfterKNegations(int[] A, int K) {
        ArrayList<Integer> negativeList = new ArrayList<Integer>();
        ArrayList<Integer> positiveList = new ArrayList<Integer>();
        int result = 0;
        for(int i = 0; i < A.length; i++) {
            if(A[i] < 0) {
                negativeList.add(A[i]);
            } else {
                positiveList.add(A[i]);
            }
        }

        if(K < negativeList.size()) {
            mergeSort(negativeList, 0, negativeList.size() - 1);
            for(int i = 0; i < K; i++) {
                result -= negativeList.get(i);
            }

            for(int i = K; i < negativeList.size(); i++) {
                result += negativeList.get(i);
            }

            for(int i = 0; i < positiveList.size(); i++) {
                result += positiveList.get(i);
            }
        } else {
            int min = Math.abs(A[0]);
            for(int i = 0; i < A.length; i++) {
                if(A[i] < 0) {
                    result -= A[i];
                } else {
                    result += A[i];
                }

                int temp = Math.abs(A[i]);
                min = min > temp ? temp : min;
            }

            int flag = (K - negativeList.size()) % 2;
            if(1 == flag) {
                result -= min * 2;
            }
        }

        return result;
    }

    private void mergeSort(ArrayList<Integer> sortValue, int start, int end) {
        if(start < end) {
            int middle = (start + end) / 2;
            mergeSort(sortValue, start, middle);
            mergeSort(sortValue, middle + 1, end);
            merge(sortValue, start, middle, end);
        }
    }

    private void merge(ArrayList<Integer> sortValue, int start, int middle, int end) {
        int[] temp = new int[end - start + 1];
        int idxLeft = start, idxRight = middle + 1;
        for(int i = 0; i <= end - start; i++) {
            temp[i] = sortValue.get(idxLeft) < sortValue.get(idxRight) ? sortValue.get(idxLeft++) : sortValue.get(idxRight++);
            if(idxRight > end) {
                idxRight--;
                sortValue.set(idxRight, Integer.MAX_VALUE);
            } else if(idxLeft > middle) {
                idxLeft--;
                sortValue.set(idxLeft, Integer.MAX_VALUE);
            }
        }

        for(int i = start; i <= end; i++) {
            sortValue.set(i, temp[i - start]);
        }
    }
}