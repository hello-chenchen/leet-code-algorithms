#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 1) {
            if()
        }
        int temp = 0;
        int tempSize = 0;
        for(int i = 0; i + tempSize < nums.size() - 1; i++) {
            if(nums[i] == val) {
                temp = nums[i];
                nums[i] = nums[i+tempSize+1];
                nums[i+tempSize+1] = temp;
                tempSize++;
                i--;
            } else {

            }
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution demo;
    demo.removeElement();
    return 0;
}
