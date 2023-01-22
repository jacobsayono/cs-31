// this code snippet tries to print all prime numbers between 3 and a given input n
// it has a number of bugs
// fix them and replace the inner while loop with a for loop

#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> x;
    int candidate = 3;
    while (candidate < n) {
        bool isPrime = true;
        x = 2;
        while (x < n) {  // replace with a for loop
            if (candidate % x == 0) {
                isPrime = false;
            }
            x = x + 1;
            if (isPrime) {
                cout << n << " ";
            }
        }
        candidate = candidate + 1;
    }
    cout << endl;

    return 0;
}