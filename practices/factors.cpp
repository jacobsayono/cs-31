// write a program that takes in an integer n where n > o
// and outputs a comma-separated list of all the factors of n

// sample input:
// enter your number: 12
// sample output:
// your factors are: 1,2,3,4,6,12

#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "enter your number: ";
    cin >> n;

    cout << "your factors are: 1";

    for (int i = 2; i <= n; ++i) {  // 2 ... n
        if (n % i == 0) {
            cout << "," << i;
        }
    }

    cout << endl;

    return 0;
}