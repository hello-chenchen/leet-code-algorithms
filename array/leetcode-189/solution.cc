#include <vector>
#include <algorithm>
#include <iostream>
// int index = 0;
//         int recyle = 0;
//         int m = 1;
//         while(index < size - 1 || m * k >= size) {
//             // cout << "swap index: " << index << " " << nums[index] << " size-k+recyle: " << size-k+recyle << " " << nums[size-k+recyle] << endl;
//             swap(nums[index], nums[size-k+recyle]);
//             index++;
//             // cout << index << " " << recyle << endl;
//             if(recyle + 1 == k) {
//                 recyle = 0;
//                 m++;
//             } else {
//                 recyle++;
//             }
//         }
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        for(int i = 0; i < nums.size() / 2; i++) {
            swap(nums[i], nums[nums.size() - i - 1]);
        }

        for(int i = 0; i < k / 2; i++) {
            swap(nums[i], nums[k - i - 1]);
        }

        for(int i = 0; i < (nums.size() - k) / 2; i++) {
            swap(nums[k + i], nums[nums.size() - i - 1]);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    vector<int> b = {1,2,3,4,5,6};
    a.rotate(b, 4);
    return 0;
}
