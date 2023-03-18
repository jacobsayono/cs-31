// write a program that takes in a number as an int
// and outputs the sum of all the digits in that number
// please assume only 3 digit numbers will be entered

// sample output:
// enter a 3 digit number: 184
// the sum of the digits in your number is 13.

#include <iostream>
using namespace std;

int main() {

    int num;
    cout << "enter your number: ";
    cin >> num;
    int score = num % 100;
    int id = (num - score) / 100;

    cout << "id:" << id << "\t" << "score: " << score << endl;

    int x;
    cout << "enter a 3 digit number: ";
    cin >> x;

    int ones = x % 10;  // 184 % 10 = 4
    int clip = x / 10;  // 184 / 10 = 18

    int tens = clip % 10;  // 18 % 10 = 8
    int hundreds = clip / 10;  // 18 / 10 = 1

    int sum = ones + tens + hundreds;

    cout << "the sum of the digits in your number is " << sum << "." << endl;

    return 0;
}