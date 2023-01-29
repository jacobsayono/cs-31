#include <iostream>
using namespace std;

int mystery(char code);

int main() {
    mystery('2');
    mystery('a');
    mystery('Z');
    mystery('d');
    mystery('1');
    mystery('c');

    return 0;
}

int mystery(char code) {
    switch(code) {
        case 'a':
        case 'b':
        case 'c':
            cout << "spooky";
            break;
        case 'd':
            cout << "feeling";
            break;
        case '1':
            cout << " ";
            break;
        case '2':
            cout << "?";
        default:
            cout << endl;
            break;
    }
    return 0;
}