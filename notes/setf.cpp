#include <iostream>
using namespace std;

int main() {
    const int I = 100;

    /* how to quit early
    if (I == 100)
    {
        // leave right away
        return 1; // exit error code associated with 100
    } */

    const double D = 10.0000;
    
    // setf: set flag
    cout.setf(ios::showpoint);  // show decimal
    cout.setf(ios::fixed);      // fixed notation (not scientific notation)
    cout.precision(2);          // 2 digits after decimal
    cout << I << endl;  // 10
    cout << D << endl;  // 10.00

    bool b = true;
    cout << b << endl;  // 0 or 1

    cout.setf(ios::boolalpha);
    cout << b << endl;  // true or false
    
    return 0;
}