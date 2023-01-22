// write a program that takes in 3 numbers to average and outputs the average of these numbers
// please assume three numbers will always be entered

// sample output:
// enter 3 numbers...
// number1: 4.0
// number2: 2.0
// number3: 8.0
// the average is 4.66667.

#include <iostream>
using namespace std;

int main() {

    double x;
    double total = 0;
    cout << "enter 3 numbers..." << endl;

    for (int i = 0; i < 3; ++i) {
        cout << "number" << i + 1 << ": ";
        cin >> x;  // cin include \n in the input buffer, so no need "\nnumber: "
        total += x;
    }
    
    double avg;
    avg = total / 3;

    cout << "the average is " << avg << "." << endl;

    return 0;
}