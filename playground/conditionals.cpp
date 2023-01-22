#include <iostream>
using namespace std;

int main() {
    const int x = -2, y = 5, z = 0, t = -4;

    bool a = x + y < z + 1;
    cout << a << endl;

    bool b = x - 2 * y + y < z * 2 / 3;
    cout << b << endl;

    bool c = 3 * y / 4 < 8 && y >= 4;
    cout << c << endl;

    bool d = t > 5 || z < 2;
    cout << d << endl;

    bool e = x * y < 10 || y * z < 10;
    cout << e << endl;

    return 0;
}