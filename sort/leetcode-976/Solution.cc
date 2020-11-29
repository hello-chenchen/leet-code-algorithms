#include <vector>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        mergeSort(A, 0, A.size() - 1);

        for(int i = A.size() - 3; i >= 0; i--) {
            if(A[i] + A[i+1] > A[i+2]) {
                return A[i] + A[i+1] + A[i+2];
            }
        }

        return 0;
    }

    void quickSort(vector<int>& sortValue, int start, int end) {
        if(start >= end) return;

        int left = start, right = end - 1;
        int endValue = sortValue[end];

        for(int i = start; i <= right; i++) {
            if(sortValue[i] <= endValue) {
                swap(sortValue[left++], sortValue[i]);
            }
        }
        swap(sortValue[left], sortValue[end]);

        quickSort(sortValue, start, left-1);
        quickSort(sortValue, left+1, end);
    }

    void mergeSort(vector<int>& sortValue, int start, int end) {
        if(start < end) {
            int middle = (start + end) / 2;
            mergeSort(sortValue, start, middle);
            mergeSort(sortValue, middle + 1, end);
            merge(sortValue, start, middle, end);
        }
    }

    void merge(vector<int>& sortValue, int start, int middle, int end) {
        vector<int> leftSubArray(sortValue.begin() + start, sortValue.begin() + middle + 1);
        vector<int> rightSubArray(sortValue.begin() + middle + 1, sortValue.begin() + end + 1);
        int idxLeft = 0, idxRight = 0;
        leftSubArray.push_back(std::numeric_limits<int>::max());
        rightSubArray.push_back(std::numeric_limits<int>::max());

        for (int i = start; i <= end; i++) {
            sortValue[i] = leftSubArray[idxLeft] < rightSubArray[idxRight]
                ? leftSubArray[idxLeft++] : rightSubArray[idxRight++];
        }
    }

    void merge1(vector<int>& sortValue, int start, int middle, int end) {
        vector<int> temp;
        int idxLeft = start, idxRight = middle + 1;
        for(int i = 0; i <= end - start; i++) {
            temp[i] = sortValue[idxLeft] < sortValue[idxRight] ? sortValue[idxLeft++] : sortValue[idxRight++];
            if(idxRight > end) {
                idxRight--;
                sortValue[idxRight] = std::numeric_limits<int>::max();
            } else if(idxLeft > middle) {
                idxLeft--;
                sortValue[idxLeft] = std::numeric_limits<int>::max();
            }
        }

        for(int i = start; i <= end; i++) {
            sortValue[i] = temp[i - start];
        }
    }
};