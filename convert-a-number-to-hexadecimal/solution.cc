#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        string res = "";
        if(0 == num) {
            return "0";
        }

        string result = "";
        toHex(num, result);

        for(int i =result.length() - 1; i >= 0; i--) {
            res += result[i];
        }

        return res;
    }

private:
    void toHex(unsigned int num, string& hexStr) {
        if(0 == num) {
            return;
        }
        int restLeft = num >> 4;
        int rightNum = num & 0x0000000f;
        auto result = m_charInt.find(rightNum);
        hexStr.append(result->second);
        toHex(restLeft, hexStr);
    }

    const map<int, string> m_charInt = {{0,"0"}, {1,"1"},{2,"2"},
        {3,"3"}, {4,"4"}, {5,"5"}, {6,"6"},{7,"7"}, {8,"8"}, {9,"9"},
        {10,"a"},{11,"b"}, {12,"c"},{13,"d"}, {14,"e"}, {15,"f"}};
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution cc;
    cout << cc.toHex(-2147483648) << endl;
    return 0;
}
