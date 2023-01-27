// # are preprocessor commands
// <library>

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
// void foo(double x); means the return is nothing

// if we later call the function: int foo(int x, int y) in our main
// but we put the parameter foo('A', true)
// we are actually sending in the integer value 65 and 1 (based on ASCII table)

int bar(int i);  // by default passed by value
// copies that value into bar
// no connection between caller and thing that got called

// "pass by value" means that the function will not be able to change the value of the passed variable
// it can make a new variable and assign it to the value that was passed
// but the new variable will be stored in a new location in memory 

int main() {
    double e = sqrt(49);  // call function
    // 3. call
    int f = foo(100.5);
    // int g = foo ("asdasd");  // passing wrong type
    // string t = foo(100.5);  // returning wrong type
    // foo(100.5, "asdasd", 10);  // parameter(s) not matching

    int zzz = 10;
    int yyy = bar(zzz);  // all these parameters get copied at runtime
    // yyy is still 100

    cout << e << endl;
    cout << f << endl;
    cout << yyy << endl;

    return 0;
}

// 2. implement
int foo(double x) {
    double y = sqrt(x);
    cout << x << endl;
    return y;  // must have a return statement;
    // warning: possible loss of data, double -> int
}

int bar(int i) {
    i++;
    return i;
}

// you can declare functions and not use them
// this won't change the compile/execution
// the program will only use snippets of that code if the function gets called in main()