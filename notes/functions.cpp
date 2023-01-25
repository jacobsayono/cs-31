#include <iostream>
#include <cmath>  // for math functions
#include <string>
using namespace std;

// 1. declare function
// 2. implement function
// 3. call function

// 1. declare
int foo(double x);  // can take in multiple parameters: int foo(double x, string s, int i);
// takes in a parameter 'double' and will return an 'int'

int main() {
    double e = sqrt(100.5);  // call function
    // 3. call
    int f = foo(100.5);
    // int g = foo ("asdasd");  // passing wrong type
    // string t = foo(100.5);  // returning wrong type
    // foo(100.5, "asdasd", 10);  // parameter(s) not matching
    return 0;
}

// 2. implement
int foo(double x) {
    double y = sqrt(x);
    cout << x << endl;
    return y;  // must have a return statement;
}

// you can declare functions and not use them
// this won't change the compile/execution
// the program will only use snippets of that code if the function gets called in main()