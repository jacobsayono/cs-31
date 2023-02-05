#include <iostream>
using namespace std;

int countChars(string s, char c);

int main() {
    cout << countChars("abracadabra", 'a') << endl;
    int n = 10 * countChars("99 cent only", '9') + 5;
    cout << n << endl;
    cout << countChars("0 rose, thou art sick!", 'f') << endl;
}

int countChars(string s, char c) {
    int total = 0;
    for (size_t k = 0; k != s.size(); k++) {
        if (s[k] == c) {
            total++;
        }
    }
    return total;
}