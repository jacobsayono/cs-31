#include <iostream>
using namespace std;

string checkeven(int a, int b, int c);

int main() {
    int a, b, c;
    cout << "write 3 integers: " << endl;
    cin >> a >> b >> c;

    cout << checkeven(a, b, c) << endl;

    // string answer;
    // answer = checkeven(a, b, c);
    // cout << answer << endl;

    return 0;
}

string checkeven(int a, int b, int c) {
    if (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
        return "YES";
    }
    else {
        return "NO";
    }
}