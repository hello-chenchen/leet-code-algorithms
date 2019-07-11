#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int rec1X1 = rec1[0], rec1Y1 = rec1[1], rec1X2 = rec1[2], rec1Y2 = rec1[3];
        int rec2X1 = rec2[0], rec2Y1 = rec2[1], rec2X2 = rec2[2], rec2Y2 = rec2[3];
        if(rec2X1 < rec1X1 && rec2Y1 < rec1Y2 && rec2X2 > rec1X1 && rec2Y2 > rec1Y1) {
            return true;
        } else if(rec2X1 < rec1X2 && rec2Y2 > rec1Y1 && rec2X2 > rec1X1 && rec2Y1 < rec1Y2) {
            return true;
        }

        return false;
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
