#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> total;
        set<int>::iterator itr;

        do{
            if(1 == n) {
                return true;
            } else if(total.find(n) != total.end()) {
                return false;
            } else {
                total.insert(n);
            }
            n = plus(n);
        } while(n != 1);

        return true;
    }

private:
    int plus(int num) {
        int result = 0;
        while(num != 0) {
            int temp = num % 10;
            result = result + temp * temp;
            num = num / 10;
        }

        return result;
    }
};