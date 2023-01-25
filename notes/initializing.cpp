#include <iostream>
using namespace std;

int main() {
    int value(23);  // same as int value = 23;
    int i(10), j(11);

    double divide = i / j;  // answer is an int but divide is declared as a double

    i++;  // same as i = i + 1;
    i--;

    i += 2;  // same as i = i + 2;

    i -= 1;  // same as i = i - 1; and i--;

    i *= 3;  // same as i = i * 3

    i += j * 100 + i++ - ++j * value;  // avoid

    // unravel this...
    j = j + 1;  // first
    i = i + (j * 100 + i - j * value);
    i = i + 1;  // last

    // typical place that ++ or -- are used is in a loop
    for (i = 1; i <= 10; ++i) {  // count to 10

    }

    for (i = 1; i <= 10; i++) {  // count to 10

    }

    for (i = 1; i <= 10; i = i + 1) {  // count to 10
        // suppose i hate the number 7
        if (i == 7) {
            break;  // same as case switch
            // return(0);
        }
    }
    // code that we want to run when i is 7

    while (i > 0) {
        for (int k = 3; k <= 5; k++) {
            cout << "i = " << i << "j = " << j << endl;

            if (k == 3) {  // panicking when it sees 3
                break;  // loop ending is the for loop in this case
            }
            cout << "statement" << endl;
            // millions of code skipped if line 49 break took place
        }
        // break to down here

        // make progress toward ending our loop
        i--;
    }

    bool b = (i < 10);
    cout << b << endl;  // 0 or 1
    // cout statements easier on your eyes to bool values
    cout.setf(ios::boolalpha);

    return 0;
}