#include <string>

using namespace std;

int number(string s);  // our assumption start from the front
int number(string s, size_t position);
int number(string s, size_t, int base);

// function name can be the same as long as
// parameters must be different in their number and type

int foo();
int foo(int i);
int foo(double d);
int foo(string s);
int foo(string s, double d, char c);

// OVERLOADING feature
int bar();
int bar(string s);
// double bar(string s);  // different return type won't work with same function name
int bar(int i);
int bar(double d);

// parameters that are assigned (with '=')
int foobar(int i, double d, string s, int j = 12, double e = 13.5, string t = "");
// the ones with '=' are optional arguments (default if no arguments are added)



// driver
int main() {
    // function call
    foo();
    foo("Pixie Stahl");  // c++ knows which foo() to run
    foo(12.555);  // calls int foo(double d)

    foobar(12, 13.5, "hello");  // then j = 12, e = 13.5, t = ""
    foobar(13, 14.5, "bye", 15);
    foobar(14, 15.5, "hello bye", 16, 12.5);
    foobar(15, 16.5, "hello bye", 17, 13.5, "asdf");

    // cannot skip, goes in order. must input j and e values manually
    foobar(15, 16.5, "goodbye", 12, 13.5, "asdf");
    foobar(12.5, 15, "bad");  // 12.5 truncates to 12 (int)
}

int foo() {
    return 0;
}

int foo(string s) {
    return 0;
}

int foo(double d) {
    return 0;
}

// but when defining the function, no need equal
int foobar(int i , double d, string s, int j, double e, string t) {
    return 0;
}