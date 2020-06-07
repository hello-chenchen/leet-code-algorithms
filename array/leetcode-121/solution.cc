#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) {
            return 0;
        }
        int left = 0, right = prices.size() - 1;

        int buy = prices[left], sale = prices[right];

        while(left < right) {
            if(buy > prices[++left]) {
                buy = prices[left];
            }

            if(sale < prices[--right]) {
                sale = prices[right];
            }
        }

        return (sale > buy && left < right) ? (sale - buy) : 0;
    }
};