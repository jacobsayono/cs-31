#include <iostream>
#include <string>
#include <cassert>  // to use assert()
using namespace std;

// think thru how you build and test functions
// how you can test through code:
int number(string s, size_t &index);  // can pass by reference for a more powerful program!
// returns -1 when the string is empty or the string doesn't start
// -1
// ""
// Pixie Stahl"
// "CS 31"

// good
// "1" -> 1
// "456" -> 456
// "456 abc 321" -> 456

int main() {
    size_t pos;
    pos = 0;
    // write test cases in code
    assert(number("", pos) == -1);  // in parenthesis must have true or false, asserts must be true!
    assert(pos == 0);
    
    // assert(number("456") == 456);  // this will fail for now, keep creating test cases 1 by 1
    
    pos = 0;
    assert(number("7", pos) == 7);
    assert(pos == 1);
    
    pos = 0;
    assert(number("8alskdjlsadj", pos) == 8);
    assert(pos == 1);
    
    pos = 0;
    assert(number("ABC", pos) == -1);
    assert(pos == 0);

    pos = 0;
    assert(number("asdlksajd", pos) == -1);
    assert(pos == 0);

    pos = 0;
    assert(number("81asldkjsald", pos) == 81);
    assert(pos == 2);
    // how to get 81:
    // first 8
    // the next time we loop 8 * 10
    // we come across 1
    // 80 + 1
    pos = 0;
    assert(number("281alskdjlks", pos) == 281);
    assert(pos == 3);
    // first 2
    // 2 * 10 + 8
    // 28 * 10 + 1
    pos = 0;
    assert(number("456", pos) == 456);  // now this will work
    assert(pos == 3);
    
    pos = 0;
    assert(number("456 abc 321", pos) == 456);
    assert(pos == 3);
    
    pos = 8;
    assert(number("456 abc 321", pos) == 321);
    assert(pos == 11);

    cout << "TESTS PASSED!" << endl;
    return 0;
}

int number(string s, size_t &index) {
    int retvalue(-1);
    int quantity(0);
    // size_t index(0);  // commented out -- now will work even if numbers don't start at the front
    // start from the front, look letter by letter
    // hoping for digit characters
    while (index < s.size() && s.at(index) >= '0' && s.at(index) <= '9') {  // char between 0 and 9 inclusive in the string
        char digit = s.at(index) - '0';  // convert char '0' to int 0
        quantity = quantity * 10 + digit;
        index++;
    }

    if (quantity != 0) {
        retvalue = quantity;
    }

    return retvalue;
}