#include <iostream>
using namespace std;

int square(int n);

int main() {
    for (int k = 1; k <=6; k++) {
        cout << "squre of " << k << " is " << square(k) << endl;
    }
}

int square(int n) {
    return n*n;
}