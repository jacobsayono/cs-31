#include <iostream>
#include "clock.h"
using namespace std;

int main() {
    Clock timer(4, 5, 30, "PM");
    cout << timer.displayStandard() << endl;
    cout << timer.displayMilitary() << endl;
}