// lecture week 1
// correct example of using cin >> string;
// introduce the concept of cin.ignore()
// built-in function getline() to cin everything in the line including white spaces

#include <iostream>
#include <string>
using namespace std;

int main() {
    int i;
    float d;
    string s;

    cin >> i; // 12\n
    cout << i << endl;

    cin >> d; // 57.5\n
    cout << d << endl;

    cin.ignore(10000, '\n');
    getline(cin, s); // jacob sayono\n
    cout << s << endl;

    return 0;
}