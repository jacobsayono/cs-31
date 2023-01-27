#include<iostream>
#include<string>
using namespace std;

int main() {
    string s("hello world");
    // position 0 is 'h'
    // position 10 is 'd'

    size_t amount = s.length();  // use size_t type instead of int
    size_t other_amount = s.size();  // synonymous as length()

    cout << amount << endl;
    cout << other_amount << endl;

    for (size_t counter = 0; counter < s.size(); counter++) {
        char c = s.at(counter);  // ask a string for the letter at that position
        // chat c = s[counter];
        cout << "counter " << counter << ": " << c << endl;
    }

    // char d = s.at(120391238);
    // build will fail at run-time
    // make sure the position is valid

    // char d = s[120391238];
    // square brackets won't fail
    // but will spit out garbage

    if ('a' < 'A') { // false
        cout << "i will never be printed" << endl;
    }

    if ('A' < 'a') {
        cout << "but i will be printed" << endl;
    }

    return 0;
}

/*
sorted order:
"A"
"AA"
"AAA"
"B"
"C"
"a"
"aa"
"b"
*/