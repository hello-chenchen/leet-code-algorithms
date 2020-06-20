#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = std::numeric_limits<int>::max();
        int result = 0;
        for(signed int i = 0; i <= prices.size(); i++) {
            if(prices[i] < minPrice) {
                minPrice = prices[i];
            }

            int temp = prices[i] - minPrice;
            if(temp > result) {
                result = temp;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution cc;
    vector<int> d = {};
    cc.maxProfit(d);
    return 0;
}
