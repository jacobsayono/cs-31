// write a program that reads in exactly 4 numbers
// and outputs the sum of only the even numbers that have been entered
// write solutions using a for loop, while loop, do-while loop

// sample output:
// enter 4 numbers:
// number1: 2
// number2: 9
// number3: -3
// number4: 6
// result: 8

#include <iostream>
using namespace std;

int main() {
    // for loop version
    int x, sum = 0;
    cout << "enter 4 numbers: " << endl;
    for (int i = 0; i < 4; i++) {
        cout << "number" << i+1 << ": ";
        cin >> x;
        
        if (x % 2 == 0) {
            sum += x;
        }
    }
    cout << "result: " << sum << endl;

    // while loop version
    int i = 0, w = 4;
    while (i < w) {
        cout << "number" << i+1 << ": ";
        cin >> x;
        
        if (x % 2 == 0) {
            sum += x;
        }
        i++;
    }
    cout << "result: " << sum << endl;
}