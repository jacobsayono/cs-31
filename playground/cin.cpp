#include <iostream>
using namespace std;

int main() {

    // int a, b, c;
    // double x, y, z;

    // cin >> a >> b >> c;
    // cin >> x >> y >> z;
    
    // cout << endl;
    // cout << a << endl;
    // cout << b << endl;
    // cout << c << endl;
    // cout << x << endl;
    // cout << y << endl;
    // cout << z << endl;

    int n; string s;
    string test = "\n";

    cout << "enter an integer: ";
    cin >> n;
    cin.ignore(10000, '\n');

    cout << "enter a string: ";
    getline(cin, s);

    cout << s << endl;
    
    return 0;
}