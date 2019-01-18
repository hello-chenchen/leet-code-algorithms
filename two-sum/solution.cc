//LINK:https://leetcode.com/problems/two-sum/
//COMPILE:g++ two-sum/solution.cc -o tmp/main -std=c++11
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        if(nums.size() < 2) {
            cout << "nums size: " << nums.size() << endl;
            return ret;
        }

        for(int i = 0; i < nums.size(); i++) {
            for(int n = 1; n < nums.size(); n++) {
                int num_i = nums[i];
                int num_n = nums[n];
                if(num_i + num_n == target) {
                    ret.push_back(i);
                    ret.push_back(n);
                    return ret;
                }
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])//FIXED: C++ requires a type specifier for all declarations
{
    vector<int> nums {2, 7, 11, 15};
    vector<int> ret = Solution().twoSum(nums, 9);

    if(2 == ret.size()) {
        cout << "result: " << ret[0] << " and " << ret[1] << endl;
    } else {
        cout << "input error!";
    }

    return 0;
}
