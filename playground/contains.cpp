#include <iostream>
using namespace std;

bool contains(string s, char c);

int main() {
    if (contains("computer science 31", '3')){
        cout << "W";
    }
    if (!contains("smallberg", 'x')){
        cout << "o";
    }
    if (contains("smallberg", 'l')){
        cout << "w";
    }
    if (contains("start your cs 31 projects early!", ' ')){
        cout << "!" << endl;
    }
}

bool contains(string s, char c) {
    for (int k = 0; k != s.size(); k++) {
        if (s[k] == c) {
            return true;
        }
    }
    return false;
}