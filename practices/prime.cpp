// this code snippet tries to print all prime numbers between 3 and a given input n
// it has a number of bugs
// fix them and replace the inner while loop with a for loop

// c is a prime number if it is not divisible by any number other than 1 and n
// in other words, c is a prime number if it is divisible by any number from 2 to n-1

#include <iostream>
using namespace std;

int main() {
    int n, x;
    cout << "enter your number: ";
    cin >> n;
    int c = 3;
    while (c < n) {
        bool isPrime = true;
        x = 2;
        while (x < c) {  // c must be divisible by any number from 2 to c-1
            if (c % x == 0) {
                isPrime = false;
            }
            x++;
        }
        if (isPrime) {
            cout << c << " ";
        }
        c++;
    }
    cout << endl;

    return 0;
}