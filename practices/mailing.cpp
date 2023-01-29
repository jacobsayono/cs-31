// write a function that returns the cost of mailing a package
// given the weight of the package in pounds and ounces
// and a cost per ounce are supplied as arguments to the function
// recall that there are 16 ounces in a pound
// then write a main program with the statements to read in
// the weight of a package (in pounds and ounces)
// and the cost per ounce for mailing
// then call your function to calculate the mailing cost
// and print the mailing cost

#include <iostream>
using namespace std;

float mailing_cost(int pounds, int ounces, float cost_per_ounce);

int main() {
    int pounds, ounces;
    float cost_per_ounce;
    cout << "enter your mailing weight (pounds): ";
    cin >> pounds;
    cout << "enter your mailing weight (ounces): ";
    cin >> ounces;
    cout << "enter your cost per ounce: ";
    cin >> cost_per_ounce;
    cout.setf(ios::showpoint);  // show decimal
    cout.setf(ios::fixed);      // fixed notation (not scientific notation)
    cout.precision(2);          // 2 digits after decimal
    cout << "your mailing cost is: $" << mailing_cost(pounds, ounces, cost_per_ounce) << endl;

    return 0;
}

float mailing_cost(int pounds, int ounces, float cost_per_ounce) {
    pounds = pounds * 16;
    ounces = ounces + pounds;
    float total_cost = ounces * cost_per_ounce;
    return total_cost;
}