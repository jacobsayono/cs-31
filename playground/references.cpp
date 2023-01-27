#include <iostream>
using namespace std;

int func(int &a);
int function(int a);

int main() {
    int d = 2;
    int c = func(d);

    cout << c << endl; // c == 8
    cout << d << endl; // c == 7

    d = 2;
    int cc = function(d);
    cout << cc << endl;
    cout << d << endl;
}

int func(int &a) {
    a += 5;
    return a + 1;
}

int function(int a) {
    a += 5;
    return a + 1;
}