#include <iostream>
using namespace std;

void foo(int &a);

int main() {
    int b = 0;
    foo(b);
    cout << b << endl;
}

void foo(int &a) {
    a += 1;
}