#include <vector>
#include <string>
#include <iostream>
#include "./../../cclib/cclib-common/inc/util/util.h"

using namespace std;
using namespace cclib::common::util;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sumResult = 0;
        vector<int> result;
        for(int i = 0; i < ops.size(); i++) {
            // cout << "i: " << i << " ops[i]: " << ops[i] << endl;

            int value = 0;
            if(0 == ops[i].compare("+")) {
                value = result.back() + result.at(result.size() - 2);
                result.push_back(value);
            }else if(0 == ops[i].compare("D")) {
                value = result.back() * 2;
                result.push_back(value);
            } else if(0 == ops[i].compare("C")) {
                value = 0 - result.back();
                result.pop_back();
            } else {
                value = stoi(ops[i]);
                result.push_back(value);
            }

            // printVectorValue(result);
            // cout << "value: " << value << " sumResult: " << sumResult << endl;

            sumResult += value;
        }

        return sumResult;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    vector<string> value = {"5","-2","4","C","D","9","+","+"};
    Solution solution;
    int result = solution.calPoints(value);
    cout << result << endl;
    return 0;
}
