#include <iostream>
#include <string>
using namespace std;

// passing an array to function
// "array parameter"
void print_array(const int array[], int n);  // initialize array parameter with a [], and the size of that array "companion parameter"
// opaque placeholder for an array of any size

void foo(int array[], int n);

int main() {

    char c = 'A';  // single quote
    string s = "whole set of chars";  // s.size() ===> 20   0-19
    string t = "";  // empty string, shortest string in c++

    // .at() ===> conversion back to single char

    for (size_t i = 0; i < s.length(); i++) {
        char c = s.at(i);
        char d = s[i];  // doesn't do any bounds checking
    }

    // ordered set of char: jump around the string

    // 'vector' spreadsheet: column or row
    // scorer ===> produces a set of int

    // every data type we've done so far we can make an array of that type

    // tell c++ upfront the size of that set
    // start counting from the zero as we walk set

    int array[10];  // a "contiguous" blob, block of space
    // we could do the following:
    const int size = 10;
    int anArray[size]; // legal

    const int n = 100;
    int someArray[n];

    // const int n;  // illegal b.c. const has to initialize immediately
    // cin >> n;  // not a modifiable l-value

    // size must be fully deremined in advance

    // not correct:
    // int i;
    // cin >> i;
    // int anArray1[i];

    // int j = 10;
    // int anArray2[j];

    // use squiggles to setup the value of each element
    int array3[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    //     "index"   "element"
    // index - element
    // 0 - 1
    // 1 - 2
    // 2 - 3
    // 3 - 4
    // 4 - 5
    // 5 - 6
    // 6 - 7
    // 7 - 8
    // 8 - 9
    // 9 - 10
    
    int array4[10] = {10, 20, 30, 40, 50};
    // 0 - 10
    // 1 - 20
    // 2 - 30
    // 3 - 40
    // 4 - 50
    // 5 - 0  // default value of arrays is 0
    // 6 - 0
    // 7 - 0
    // 8 - 0
    // 9 - 0

    // default value of bool is false
    bool boolean;
    
    // normal variables
    // int i;  // 3.2345245e65 throw garbage

    // with arrays, turn your code into lots of loops
    // arrays don't support the dot guy
    // no .at()
    // only way to get an element in the array is the []
    int array5[10];
    array5[0] = 10;  // assignment statement: walk to index 0 and give element 10
    array5[1] = 20;
    array5[2] = 30;
    array5[3] = 40;
    array5[4] = 50;  // make sure in bounds
    int k = array5[0] + array5[1] + array5[3];

    // bad:
    // array.at(0) = 10;
    // array.size();
    // array.length();

    // print an array: requires a loop
    for (int i = 0; i < 10; i++) {
        cout << "array[" << i << "] = " << array[i] << endl;
    }

    // can sort array
    // locate the biggest or smallest

    // write code that identifies biggest item in the set
    // array size n
    // {1, 10, 7, 2, 14, 5} --> 14
    int biggest = array[0];  // initialize by throwing in first element as biggest
    for (int i = 0; i < n; i++) {
        if(array[i] > biggest) {
            biggest = array[i];
        }
    }
    cout << "biggest one is = " << biggest << endl;


    // passing an array to function
    // "array paramenter"
    // int a[100];  // filled with gibberish
    int a[100] = {3, 3, 3, 3, 3};  // all the rest 0
    int b[5] = {1, 2, 3, 4, 5};

    foo(b, 5);
    // array was not copied
    // in function foo():
    // b[0] = 100;
    // b[1] = 1000;
    // done!

    print_array(b, 5);
    print_array(a, 100);
    print_array(a, 5);  // prints just the first 5 elements (tricks the program to see only array of size 5)

    foo(b, 5);
    print_array(b, 5);

    // super bad
    // print_array(b, 304284828);  // these statements can run...
    // print_array(a, 1920382104);
    // driver code is sending that n, c++ takes that size a "given"

    return 0;
}

void print_array(const int array[], int n) {  // read only
    // print the items in the array
    // bounds size limit
    for (int i = 0; i < n; i++) {
        cout << "array[" << i << "] = " << array[i] << endl;
    }
}

// c++ does not pass arrays by value (too big to copy!)
// intead, passes "similar to by reference"

void foo(int array[], int n) {
    if (n > 2) {
        array[0] = 100;
        array[1] = 1000;
    }
}

// since passed by "reference", this means array forever changed

// funciton print_array() only accesses the array
// read only
// never changes
// the array is FIXED read only value
// FIXED == CONST

// function foo() changes the array