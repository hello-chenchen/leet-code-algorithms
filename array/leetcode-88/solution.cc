#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0; i < n; i++) {
            cout << "i: " << i << " : " << nums2[i] << endl;
            for(int j = 0; j < m + n; j++) {
                cout << "i: " << i << " : " << nums2[i] << " j: " << j << " : " << nums1[j] << endl;
                if(nums2[i] < nums1[j]) {
                    swap(nums2[i], nums1[j]);
                    i--;
                    break;
                }

                if(0 == nums1[j] && nums1[j-1] > 0 && 0 != j) {
                    nums1[j] = nums2[i];
                    break;
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution cc;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    cc.merge(nums1, 3, );
    return 0;
}
[0,0,3,0,0,0,0,0,0]
3
[-1,1,1,1,2,3]
6