#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int totalNum = m + n;

        int p1 = m - 1, p2 = n - 1;
        for(int i = m + n - 1; i >= 0; i--) {
            if(p1 < 0) {
                nums1[i] = nums2[p2--];
                continue;
            }

            if(p2 < 0) {
                return;
            }

            if(nums1[p1] < nums2[p2]) {
                nums1[i] = nums2[p2--];
            } else {
                nums1[i] = nums1[p1--];
            }
        }
    }
};