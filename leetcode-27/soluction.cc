#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int first = -1;
        int size = nums.size();
        for(int i = 0; i < size; i++) {
                if(nums[i] != val) {
                    if(first < i) {
                        std::swap(nums[i], nums[first]);
                    }
                } else {
                    if(first < i && first > 0) {
                        first = i;
                    }
                }
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */

    return 0;
}
