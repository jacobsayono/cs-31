// write a function checkeven which accepts 3 integer parameters
// and prints YES if all three numbers are even
// otherwise the function prints NO
// then write a main program with the statements to read in 3 intergers
// then call your function to deteremine wheteher the data entered was all even

#include <iostream>
using namespace std;

string checkeven(int a, int b, int c);

int main() {
    int a, b, c;
    cout << "write 3 integers: " << endl;
    cin >> a >> b >> c;

    cout << checkeven(a, b, c) << endl;

    return 0;
}

string checkeven(int a, int b, int c) {
    if (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
        return "YES";
    }
    else {
        return "NO";
    }
}