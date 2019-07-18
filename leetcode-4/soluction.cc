#include <vector>
using namespace std;

class soluction {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int m = nums1.size(), n = nums2.size();

            int middleIndex = (m + n + 1) / 2;
            bool isOdd = (((m + n + 1) / 2) == ((m + n) / 2)) ? false : true;

            int numIndex1 = -1, numIndex2 = -1;
            while(1 != middleIndex) {
                int half = middleIndex / 2;

                int left = (half + numIndex1) < m ? (half + numIndex1) : (m - 1);
                int right = (half + numIndex2) < n ? (half + numIndex2) : (n - 1);
                if (nums1[left] < nums2[right]) {
                    numIndex1 = left;
                } else {
                    numIndex2 = right;
                }
                middleIndex -= half;
            }

            if(isOdd) {
                return nums1[numIndex1] > nums2[numIndex2] ? nums1[numIndex1] : nums2[numIndex2];
            } else {
                int left = nums1[numIndex1] > nums2[numIndex2] ? nums1[numIndex1] : nums2[numIndex2];
                int right =
            }
        }

    private:
        double getMiddleValue(vector<int>& nums1, vector<int>& nums2, bool oddOrEven, int left, int right) {

        }
};