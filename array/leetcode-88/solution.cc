#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(0 == n) {
            return;
        }
        vector<int> result(m+n);
        int p1 = 0, p2 = 0;
        for(int i = 0; i < m + n; i++) {
            if(p1 > m - 1) {
                result[i] = nums2[p2++];
                continue;
            }
            if(p2 > n -1) {
                result[i] = nums1[p1++];
                continue;
            }
            
            if(nums1[p1] < nums2[p2]) {
                result[i] = nums1[p1++];
            } else {
                result[i] = nums2[p2++];
            }
        }

        nums1 = result;
        // for(int i = 0; i < n; i++) {
        //     cout << "i: " << i << " : " << nums2[i] << endl;
        //     for(int j = 0; j < m + n; j++) {
        //         cout << "i: " << i << " : " << nums2[i] << " j: " << j << " : " << nums1[j] << endl;
        //         if(nums2[i] < nums1[j]) {
        //             swap(nums2[i], nums1[j]);
        //             i--;
        //             break;
        //         }

        //         if(0 == nums1[j] && nums1[j-1] > 0 && 0 != j) {
        //             nums1[j] = nums2[i];
        //             break;
        //         }
        //     }
        // }
    }
};