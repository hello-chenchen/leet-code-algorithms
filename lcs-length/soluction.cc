#include <iostream>
#include <string>

using namespace std;

class Soluction {
    public:
        char* lcsLength(string x, string y) {
            int m = x.size();
            int n = y.size();
            char b[m][n] = {0};
            int c[m+1][n+1] = {0};

            for(int i = 1; i <= m; i++) {
                for(int j = 1; j <= n; j++) {
                    if(x[i] == y[j]) {
                        c[i][j] = c[i-1][j-1] + 1;
                        b[i][j] = '=';
                    } else if(c[i-1][j] >= c[i][j-1]) {
                        c[i][j] = c[i-1][j];
                        b[i][j] = '>';
                    } else {
                        c[i][j] = c[i][j-1];
                        b[i][j] = '<';
                    }
                }
            }

            // char** c = *b;
            printLCS(b, x, m, n);
            return *b;
        }

        void printLCS(char** b, string x, int i, int j) {
            if(i == 0 || j == 0) {
                return;
            }
            if(b[i][j] == '=') {
                printLCS(b, x, i-1, j-1);
                cout << x[i];
            } else if(b[i][j] == '>') {
                printLCS(b, x, i-1, j);
            } else {
                printLCS(b, x, i, j-1);
            }
        }
};