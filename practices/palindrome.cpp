// write a program that reads two integers and determines whether or not
// these two integers are palindromes of one another
// a palindrom number is a value that reads the same forwards and backwards
// hint: use % and / to break the value into its different digits

// sample input:
// 62 26
// sample output:
// true

// sample input:
// 154 451
// sample output:
// true

// sample input:
// 25 56
// sample output:
// false

#include <iostream>
using namespace std;

int main() {
    cout << "enter 2 numbers: " << endl;
    
    int a, b;
    cout << "number1: ";
    cin >> a;
    cout << "number2: ";
    cin >> b;

    int ones = a % 10;
    int clip1 = a / 10;
    int tens = clip1 % 10;
    int clip2 = clip1 / 10; // hundreds

    int next = clip2 % 10;
    if (next == 0) {
        // stop while loop
    }

    while 


    return 0;
}