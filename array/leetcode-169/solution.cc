#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> result;
        for(int i = 0; i < nums.size(); i++) {
            auto iter = result.find(nums[i]);
            if(result.end() == iter) {
                result.insert({nums[i], 1});
            } else {
                iter->second++;
            }
        }

        int index = 0, max = 0;
        auto begin = result.begin();
        while(begin != result.end()) {
            if(max < begin->second) {
                max = begin->second;
                index = begin->first;
            }
            begin++;
        }

        return index;
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    vector<int> b = {3,2,3};
    a.majorityElement(b);
    return 0;
}
