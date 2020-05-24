#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return !(rec1[0] >= rec2[2] || rec1[2] <= rec2[0] || rec1[1] >= rec2[3] || rec1[3] <= rec2[1]);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution cc;
    vector<int> a = {0, 0, 1, 1};
    vector<int> b = {1, 0, 2, 1};
    cc.isRectangleOverlap(a, b);
    return 0;
}
