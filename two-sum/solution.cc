//LINK:https://leetcode.com/problems/two-sum/
//COMPILE:g++ two-sum/solution.cc -o tmp/main -std=c++11
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numMap;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            int num2 = target - nums[i];
            auto search = numMap.find(num2);
            if(search != numMap.end()) {
                result.push_back(search->second);
                result.push_back(i);
            } else {
                numMap.insert(std::pair<int, int>(nums[i], i));
            }
        }

        return result;
    }
};

int main(int argc, char const *argv[])//FIXED: C++ requires a type specifier for all declarations
{
    vector<int> nums {2, 5, 5, 11};
    vector<int> ret = Solution().twoSum(nums, 10);

    if(2 == ret.size()) {
        cout << "result: " << ret[0] << " and " << ret[1] << endl;
    } else {
        cout << "input error!";
    }

    return 0;
}
