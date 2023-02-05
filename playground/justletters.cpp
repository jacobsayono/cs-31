#include <iostream>
using namespace std;

string justLetters(string s);

int main() {
    cout << justLetters("CS 31 began January 5.") << endl;
}

string justLetters(string s) {
    string result = "";
    for (int k = 0; k != s.size(); k++) {
        if (islower(s[k])) {
            result += s[k];
        }
        if (isupper(s[k])) {
            result += tolower(s[k]);
        }
    }
    return result;
}