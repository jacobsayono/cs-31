// write a function that does integer division without using the division operator (/)
// return -1 if the second number is 0
// your main driver code should recognize that -1 and print an error statement as shown below
// "error: cannot divide by 0"
// then write a main program with the statements to read in 2 integers
// then call your function

#include <iostream>
using namespace std;

int integer_divide(int num, int den);

int main() {
    int num, den;
    cout << "enter your numerator: ";
    cin >> num;
    cout << "enter your denominator: ";
    cin >> den;
    int x = integer_divide(num, den);

    if (x == -1) {
        cout << "error: cannot divide by 0" << endl;
    }
    
    else {
        cout << x << endl;
    }

    return 0;
}

int integer_divide(int num, int den) {
    if (den == 0) {
        return -1;
    }

    int n = 0;
    while (num != (n * den)) {  // 6/4 -> 6 != (1 * 4)
        n++;
        if ((n*den) > num) {
            return n - 1;
        }
    }

    return n;            
}