#include <iostream>
using namespace std;

void factorial(int n);

int main() {
    for (int k = 1; k <= 6; k++) {
        factorial(k);
    }
}

void factorial(int n) {
    int prod = 1;
    for (int i = 2; i <= n; i++) {
        prod *= i;
    }
    cout << "factorial of " << n << " is " << prod << endl;
}