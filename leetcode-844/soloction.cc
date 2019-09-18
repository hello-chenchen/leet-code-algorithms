#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sumResult = 0;
        vector<int> result;
        for(int i = 0; i < ops.size(); i++) {

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

            sumResult += value;
        }

        return sumResult;
    }
};