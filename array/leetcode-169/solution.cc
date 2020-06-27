#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int result = 0 == nums.size() ? 0 : nums[0];
        for(int i = 0; i < nums.size(); i++) {
            if(0 == count) {
                result = nums[i];
                count++;
            } else if(result == nums[i]) {
                count++;
            } else{
                count--;
            }
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    vector<int> b = {3,2,3};
    a.majorityElement(b);
    return 0;
}
