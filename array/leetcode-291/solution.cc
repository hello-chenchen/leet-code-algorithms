#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> compare;
        set<int>::iterator it;

        for(int i = 0; i < nums.size(); i++) {
            if(compare.find(nums[i]) != compare.end()) return true;
            
            compare.insert(nums[i]);
            if(compare.size() > k) {
                compare.erase(nums[i-k]);
            }
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution cc;
    vector<int> a = {1,2,3,1,2,3};
    cout << cc.containsNearbyDuplicate(a, 2);
    return 0;
}