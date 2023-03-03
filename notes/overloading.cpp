// keyboard symbols that you can use between variables
// + - * / == != > <
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>

int main() {
using namespace std;

class Number {
    private:
        int mValue;
    public:
        Number();
        Number(int initValue);

        int getValue();
        void setValue(int value);
        void printAsRomanNumeral();
};

Number operator +(Number n1, Number n2);
Number operator +(Number n1, Number n2) {
    Number retValue;
    int total = 0;
    total = total + n1.getValue();
    total = total + n2.getValue();  // combining together those arguments
    retValue.setValue(total);
    return retValue;
}

Number operator +(Number n1, int i);
Number operator +(Number n1, int i) {
    Number retValue;
    int total = i;
    total += n1.getValue();  // combined alue of n1 and i
    retValue.setValue(total);
    return retValue;
}

int n, t;
// an operator is a function with a funny name
// when you call it, without using ()s
Number t = n + 100; // operator +(Number, int);
Number u = n + t;  // operator +(Number, Number);

int i = -7; // takes 1 argument
int j = +i;

// a whole bunch of adds...
int z = i + j + 10 + 100 + 20 + -20;
// (((((i + j) + 10) + 100) + 20) + -20);  // c++ eats 2 arguments at a time and call the operator again

if (i == j) {}  // condition always returns a bool

// CONSISTENT RULE:
// operator overloading
//     2 arguments --- not really
//     return whatever you want --- not really

bool operator >( , );
bool operator ==( , );
if (n == m) {}  // won't work

bool operator ==(Number n1, Number n2);
bool operator ==(Number n1, Number n2) {
    // figure out are they "equal"?
    // underlying values match...
    return (n1.getValue() == n2.getValue());
    // a little different .getValue() return ints
}



    string s = "Hot";
    string t = "Dog";

    Number n(5);
    Number m(10);
    // operator overloading "convenience"
    // this won't work out of the box...
    Number fifteen = n + m;
    Number value = add(n, m);
    Number four = n - 1;  // "everyday average function"    no dot guy '.'  so it's not Number::add     add()
    Number six = n + 1;
    Number differentway = subtract(n, 1);
    n.(-1);
    n.setValue(100);

    Number add(Number n1, Number n2);
    Number add(Number n1, int i);

    cout << n.getValue();  // exists    cout << int
    cout << six.getValue();
    cout << n;  // out of the box   NOT WORK...

    int i = 7;
    cout << i;
    cout.precision(2);
    cout.setf(ios::showpoint);  // tells you cout is an object!
    // output stream    CLASS: ostream      OBJECT: cout

    ostream operator <<(ostream outs, int value);
    ostream operator <<(ostream outs, Number value);

    int q = 1;
    int w = 2;
    int e = 3;
    // blah blah guys '<<' invocation is "stackable"
    (((cout << i) << j) << k);

    // small pieces of magic...
    // ostream      that class is kinda weird
    // feature      must pass streams by reference
    ostream &operator <<(ostream &outs, Number value);

    // can print out in roman numerals
    ostream &operator <<(ostream &outs, Number value) {
        // print out value      underlying int...       getValue()
        // "persistent" data
        int data = value.getValue();
        outs << data;
        return outs;
    }

    Number seven = 7;
    cout << seven << endl;

    int i;
    cin >> i;
    // what is cin      OBJECT istream
    Number n;
    cin >> n;

    istream &operator >>(istream &ins, int value);
    // special magic...
    // all streams need to be passed by reference
    istream &operator >>(istream &ins, Number &value);

    istream &operator >>(istream &ins, Number &value) {
        int i;
        ins >> i;
        value.setValue(i);
        return ins;
    }

    Number n;
    cin >> n;
    // over... has n changed?   YES
    // driver notice that change?   YES
}