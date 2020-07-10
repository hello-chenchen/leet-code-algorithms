#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> temp(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            temp[nums[i] - 1] = nums[i];
        }

        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            if(0 == temp[i]) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution aa;
    vector<int> b = {1, 2, 3};
    aa.findDisappearedNumbers(b);
    return 0;
}
