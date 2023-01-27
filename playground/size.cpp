#include <iostream>
#include <string>
using namespace std;

void printEveryOther(string s);
void printEveryOtherV2(string s);

int main() {
    string s;
    cout << "write your string: ";
    // cin >> s;
    getline(cin, s);

    printEveryOther(s);
    cout << endl;
    printEveryOtherV2(s);
    cout << endl;
}

void printEveryOther(string s) {
    for (int i = 0; i < s.size(); i+=2) {
        // cout << s[i];
        cout << s.at(i);
    }
    // return;
}

void printEveryOtherV2(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (i % 2 == 0) {
            cout << s.at(i);
        }
    }
}