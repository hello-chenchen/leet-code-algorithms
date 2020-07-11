#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i < nums.size(); i++) {
            int temp = 0;
            while(nums[i] == 1) {
                temp++;
                i++;
            }

            result = temp > result ? temp : result;
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution cc;
    return 0;
}
