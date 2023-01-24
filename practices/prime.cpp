// this code snippet tries to print all prime numbers between 3 and a given input n
// it has a number of bugs
// fix them and replace the inner while loop with a for loop

// c is a prime number if it is not divisible by any number other than 1 and n
// in other words, c is a prime number if it is divisible by any number from 2 to n-1

#include <iostream>
using namespace std;

int main() {
    // n: user input
    // x: iteration variable to test for divisibility of a number
    // c: the actual prime number

    int n, x;
    cout << "enter your number: ";
    cin >> n;

    int c = 3;
    while (c <= n) {  // check for every number from 3 to given input n
        bool isPrime = true;
        x = 2;  // from 2
        while (x < c) {  // to c-1
            if (c % x == 0) {  // c must be divisible by any number from 2 to c-1
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

    // for loop version
    for (int c = 3; c <= n; c++) {  // from 3 to n
        bool isPrime = true;
        for (int x = 2; x < c; x++) {  // from 2 to (c-1)
            if (c % x == 0) {  // if c is divisible by tester x
                isPrime = false;  // then c is not a prime number
            }  // just need to hit divisibility property once to turn off boolean and skip the print
        }
        if (isPrime) {  // if false, then skip to x++
            cout << c << " ";
        }
    }
    cout << endl;

    return 0;
}