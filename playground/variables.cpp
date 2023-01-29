#include <iostream>
using namespace std;

int main() {
    int num;
    double val;

    num = 17 / 2.0 + 4;
    val = 17 / 2.0 + 4;

    num = 11 % 6 / 2 - 1;
    val = 11 % 6 / 2 - 1;

    num = 11 % 6 / 2.0 - 1;
    val = 11 % 6 / 2.0 - 1;

    num = 3 - (5 + 10 / (2 * 2));
    val = 3 - (5 + 10 / (2 * 3.0));

    val = 4.5 * (5 - 3);
    num = val;

    num = 15 / 2 % 3 - 1;

    num = 7 * 2 - 5 / 3;
    val = num;

    cout << num << endl;
    cout << val << endl;

    cout << 9/10 << endl; // 0.9 -> int always rounds down -> 0

    return 0;
}