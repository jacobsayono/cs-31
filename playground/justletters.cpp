#include <iostream>
#include <cctype>
using namespace std;

string justLetters(string s);

int main() {
    cout << justLetters("CS 31 began January 5.") << endl;
    cout << tolower('A') << endl;
    cout << tolower('a') << endl;

    string a = "Testing This Sentence!";
    string b = "";
    for (int i = 0; i < a.size(); i++) {
        b += tolower(a[i]);
    }
    cout << b << endl;
}

string justLetters(string s) {
    string result = "";
    for (int k = 0; k != s.size(); k++) {  // size_t is better
        // these conditions only checks for and returns letters
        if (islower(s[k])) {
            result += s[k];
        }
        if (isupper(s[k])) {
            result += tolower(s[k]);
        }
    }
    return result;
}