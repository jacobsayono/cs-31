// write a function that does integer multiplication without using the multipliication operator (*)
// return true if the multiplied value equals the third argument, otherwise false
// then write a main program with the statements to read in 3 integers
// then call your function passing these 3 arguments

#include <iostream>
using namespace std;

bool integer_multiplication(int a, int b, int check_ans);

int main() {
    int a, b, check_ans;
    cout << "enter 1st number: ";
    cin >> a;
    cout << "enter 2nd number: ";
    cin >> b;
    cout << "enter your check answer: ";
    cin >> check_ans;

    cout << integer_multiplication(a, b, check_ans) << endl;

    return 0;
}

bool integer_multiplication(int a, int b, int check_ans) {
    int ans = 0;
    for (int i = 0; i < b; i++) {
        ans += a;
    }

    return ans == check_ans;
}