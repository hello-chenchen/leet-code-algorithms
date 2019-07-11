#include <vector>
#include <stack>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> upPrice;
        int result = 0;
        for(int i =0; i < prices.size(); i++) {
            if(0 == upPrice.size()) {
                upPrice.push_back(prices[i]);
                continue;
            }

            if(prices[i] <= upPrice[upPrice.size()-1]) {

                if(upPrice.size() <= 1) {
                    upPrice.pop_back();
                    i--;
                    continue;
                }

                result += upPrice[upPrice.size()-1] - upPrice[0];
                upPrice.clear();
                i--;
            } else {
                upPrice.push_back(prices[i]);
            }
        }

        if(upPrice.size() > 1) {
            result += upPrice[upPrice.size()-1] - upPrice[0];
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution cc;
    vector<int> a = {7,6,4,3,1};
    cout << cc.maxProfit(a);
    return 0;
}
