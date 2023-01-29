#include <iostream>
using namespace std;

void mystery(int a, int b);

int main() {
    int a = 5, b = 10;
    cout << "a: " << a << " b: " << b << endl;
    mystery(a, b);
    cout << "a: " << a << " b: " << b << endl;

    return 0;
}

void mystery(int a, int b) {
    int count = 0;
    while (count < 2) {
        a = a + b/2;
        b = a + 5;
        cout << "a: " << a << " b: " << b << endl;
        count++;
    }
}

/*
a: 5 b: 10
a: 10 b: 15
a: 17 b: 22
a: 5 b: 10
*/