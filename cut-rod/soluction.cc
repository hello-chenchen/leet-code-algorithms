#include <iostream>

using namespace std;

class Soluction {
    public:
        int bottomUpCutRod(int* p, int n) {
            int r[n + 1] = {0};
            for(int j = 1; j <= n; j++) {
                int q = 0;
                for(int i = 1; i <= j; i++) {
                    q = max(q, p[i] + r[j-i]);
                }
                r[j] = q;
            }

            return r[n];
        }
};

int main(int argc, char const *argv[])
{
    /* code */
    int p[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    Soluction aa;
    int a = aa.bottomUpCutRod(p, 9);
    cout << "a: " << a << endl;
    return 0;
}
