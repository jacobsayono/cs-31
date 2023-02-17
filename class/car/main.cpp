#include <iostream>
#include "car.h"
// #include "car.cpp"  // never #include a .cpp file in this course

int main() {
    // initializing a class immediately invokes the constructor
    Car c("Honda", "Prelude");

    c.start();
    c.drive();
    c.honk();
    // c.mMake = "Honda";  // no access to private fields

    Car d;  // do not include () if invoking no-argument constructor

    // class string, object s (of that class)
    string s = "hello world!";
    s.length();

    return 0;
}