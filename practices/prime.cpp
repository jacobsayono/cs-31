// this code snippet tries to print all prime numbers between 3 and a given input n
// it has a number of bugs
// fix them and replace the inner while loop with a for loop

// n is a prime number if n is not divisible by any number other than 1 and n
// in other words, n is a prime number if n is divisible by any number from 2 to n-1

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
        candidate++;
    }
    cout << endl;

    return 0;
}