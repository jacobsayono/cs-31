#include<iostream>
using namespace std;

// pass by value
void foo(int a, int b);

// pass by reference
void bar(int &x, int &y);


int main() {
    cout << "in main() function: " << endl;
    int a = 1;
    int b = 2;
    cout << "main a and b = " << a << " " << b << endl;
    cout << endl;

    // foo (1, 2); works as well because function declaration parameter is without &
    foo(a, b);  // prints a, b, a_function, b_function
    cout << endl;

    cout << "in main() function: " << endl;
    a = a + 1;
    b = b + 1;
    cout << "new main a and b = " << a << " " << b << endl;


    foo (a, b);
    cout << endl;

    cout << "in main() function: " << endl;
    int x = 1;
    int y = 2;
    cout << "main x and y = " << x << " " << y << endl;
    bar(x, y);
    cout << endl;

    cout << "in main() function: " << endl;
    x = x + 1;
    y = y + 1;
    cout << "new main x and y = " << x << " " << y << endl;
    bar(x, y);
    cout << endl;
    cout << "x and y = " << x << " " << y << endl;

    cout << endl;
    cout << "printing out &x and &y: " << endl;
    cout << "&x = " << &x << endl;
    cout << "&y = " << &y << endl;

    return 0;
}

// pass by value
void foo(int a, int b) {
    cout << "in foo() function: " << endl;

    cout << "function a = " << a << endl;
    cout << "function b = " << b << endl;

    a = a + 1;
    cout << "new function a = " << a << endl;
    b = b + 1;
    cout << "new function b = " << b << endl;
}

// pass by reference
void bar(int &x, int &y) {
    cout << "in bar() function: " << endl;

    cout << "function x = " << x << endl;
    cout << "function y = " << y << endl;

    x = x + 1;  // changes the value of x in main()
    cout << "new function x = " << x << endl;
    y = y + 1;  // changes the value of y in main()
    cout << "new function y = " << y << endl;
}
// pass by reference: no copy, use the same actual variable
// if main function changes x, the variable in the function will also change