// for vs while vs do-while loops

#include <iostream>
using namespace std;

int main() {

    // for loop
    for (int f = 0; f < 5; f++) {
        cout << f;
    }
    cout << endl;

    // while loop
    int n = 5;
    int w = 0;
    while (w < n) {
        cout << w;
        w++;
    }
    cout << endl;

    // do-while loop
    int m = 5;
    int d = 0;
    do {
        cout << d;
        d++;
    } while (d < m);
    cout << endl;

    return 0;
}