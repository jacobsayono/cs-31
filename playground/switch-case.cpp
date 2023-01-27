#include <iostream>
using namespace std;

int main() {
    cout << "enter weekday: ";
    int weekday;
    cin >> weekday;

    if (weekday == 1) {
        cout << "rainy days and mondays get me down";
    }
    else if (weekday == 2) {
        cout << "ruby tuesday";
    }
    else if (weekday == 6 || weekday == 7) {
        cout << "wonderful weekend";
    }
    else {
        cout << "regular day";
    }

    switch (weekday) {
        case 1:
            cout << "rainy days and mondays get me down";
            break;
        case 2:
            cout << "ruby tuesday";
            break;
        case 6:
        case 7:
            cout << "wonderful weekend";
            break;
        default:
            cout << "regular day";
    }


    return 0;
}