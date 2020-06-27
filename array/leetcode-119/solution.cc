#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> cycle = {};
        for(int i = 0; i<= rowIndex; i++) {
            vector<int> item = {};
            for(int j = 0; j <= i; j++) {
                if(0 == j || i == j) {
                    item.push_back(1);
                } else {
                    item.push_back(cycle[j-1] + cycle[j]);
                }
            }
            cycle = item;
        }
        return cycle;
    }
};