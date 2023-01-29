#include <iostream>
using namespace std;

int three(int, int);

int main() {
    int f;
    f = 1;
    int i = 1;
    while (i < 5) {
        f = three(i, f);
        cout << f << endl;
        i = i + 1;
    }
}

int three(int a, int b) {
    int z;
    z = a + a * b;
    return z;
}