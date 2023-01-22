// what is the output of the following code?

#include <iostream>
using namespace std;

int main () {
    int a = 10, b = 22;
    while (a / 2 >= 1) {
        a--;
        cout << a << endl;
        if ((a + b) % 2 == 0) {
            a--;
            cout << a << endl;
            b /= 2;
        }
    }

    return 0;
}