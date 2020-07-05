#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> compare;
        map<int, int>::iterator it;

        for(int i = 0; i < nums.size(); i++) {
            it = compare.find(nums[i]);
            if(it != compare.end()) {
                if(i - it->second <= k) return true;
                it->second = i;
                continue;
            }
            compare.insert(pair<int, int>(nums[i], i));
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution cc;
    vector<int> a = {1, 0, 1, 1};
    cout << cc.containsNearbyDuplicate(a, 1);
    return 0;
}
