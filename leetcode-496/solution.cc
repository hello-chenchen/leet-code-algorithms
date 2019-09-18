#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0; i < nums1.size(); i++) {
           for(int n = 0; n < nums2.size(); n++) {
               bool flag = false;
               if (nums2[n] == nums1[i]) {
                    while (n < nums2.size()) {
                        if (nums2[n] > nums1[i]) {
                            nums1[i] = nums2[n];
                            flag = true;
                            break;
                        }
                        n++;
                    }
                    if(flag) break;
                    nums1[i] = -1;
                }
           }
       }

       return nums1;
    }
};