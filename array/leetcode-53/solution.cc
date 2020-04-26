#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(0 == nums.size()) {
            return numeric_limits<int>::min();
        }

        int sum = nums[0];
        int second_sum = sum;
        for(int i = 1; i < nums.size(); i++) {
            cout << sum << " " << second_sum << " " << nums[i] << endl;
            if(0 <= nums[i]) {
                if(sum < 0) {
                    sum = nums[i];
                } else {
                    sum += nums[i];
                }
            } else {
                if(i < nums.size() - 2) {
                    sum = nums[++i];
                    second_sum = sum;
                }
            }
        }

        return sum > second_sum ? sum : second_sum;
    }
};

int main(int argc, char const *argv[])
{
    Solution cc;
    vector<int> aa = {-2,1,-3,4,-1,2,1,-5,4};
    int result = cc.maxSubArray(aa);
    cout << result << endl;
    return 0;
}
