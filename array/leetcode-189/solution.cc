#include <vector>
#include <algorithm>
#include <iostream>
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
