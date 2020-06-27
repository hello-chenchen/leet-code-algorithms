#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            auto a = st.find(nums[i]);
            if(st.end() != st.find(nums[i])) {
                return true;
            }
            st.insert(nums[i]);
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution cc;
    vector<int> i = {1 , 2, 1};
    cc.containsDuplicate(i);
    return 0;
}
