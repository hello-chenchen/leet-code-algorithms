#include <vector>
#include <iostream>
#include "./../../cclib/cclib-common/inc/util/util.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result = {};
        vector<int> cycle = {};
        for(int i = 0; i< numRows; i++) {
            vector<int> item = {};
            for(int j = 0; j <= i; j++) {
                if(0 == j || i == j) {
                    item.push_back(1);
                } else {
                    item.push_back(cycle[j-1] + cycle[j]);
                }
            }
            cycle = item;
            result.push_back(cycle);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution cc;
    vector<vector<int>> result = cc.generate(3);
    for(int i = 0; i < result.size(); i++) {
        cclib::common::util::printVectorValue(result.at(i));
    }
    return 0;
}
