#include <iostream>
using namespace std;
int three(int, int);

int main() {
    int a, b;
    a = 3;
    b = 4;
    cout << three(a,b);
    return 0;
}

int three(int x, int y) {
    int a;
    a = x + y;
    return a;
}