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
    cin.ignore(10000, '\n');

    int reverse = 0;  // start with 0th place, initialized outside while loop so we can use this information outside loop
    while (a != 0) {  // stop while loop when interated over all digits
        int digit = a % 10;  // store right-most digit
        reverse = reverse * 10 + digit;  // move previous digit to the left and put next digit on the right
        a = a / 10;  // leftover after clipping right-most digit
    }

    if (reverse == b) {
        cout << "YES, your numbers ARE a palindrome!" << endl;
    }
    else {
        cout << "NO, your numbers ARE NOT a palindrome..." << endl;
    }

    return 0;
}