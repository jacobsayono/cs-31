#include <iostream>  // (system defined <>)
#include "enum.h"  // connects the header file (user defined "")
using namespace std;

enum CollegeYear {FRESHMAN, SOPHOMORE, JUNIOR, SENIOR};
void graduate(CollegeYear &y);

int graduate(int y);

int main() {
    // we are not limited to just the datatypes we have seen so far
    // create datatypes of our own

    // first way:
    // enum
    // we need to know all the "examplars" of that type in advance

    // "int" == "DaysOfTheWeek"
    // "i" == "MONDAY, ..."
    int i;
    // enum DaysOfTheWeek { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY };
    //                    0        1         2         3        4         5        6

    // enumeration "et of defined values", cannot be changed
    // by default:
    // value is an underlying int value
    // good for case statement
    // "minimal" ints, only thing that works is = and ==

    // another concept
    // TextbookAuthor {} always changes so cannot use enum

    int j = 100;
    int k = 200;
    // enum Suit { SPADE = 100, DIAMOND = 200, CLUB = 100, HEART = 200 };
    Suit s;
    Suit t = DIAMOND;
    switch(s) {
        case SPADE:
        case CLUB:
            break;
        case HEART:
        case DIAMOND:
            break;
    }

    enum Color {RED, BLACK = 100, WHITE, BLUE, GREEN = -10};
    //            0    100          101   102   -10
    int m = 101;
    Color c = WHITE;
    switch(c) {
        case RED:
        case BLACK:
            c == !WHITE;
        default:
            c = GREEN;
    }

    s = HEART;
    CollegeYear you = FRESHMAN;
    graduate(you);
}

void graduate(CollegeYear &y) {
    // push them to next year
    // y = y + 1;  // enum does not support + _ * // ++
    switch(y) {
        case FRESHMAN:
            y = SOPHOMORE;
            break;
        case SOPHOMORE:
            y = JUNIOR;
            break;
        case JUNIOR:
            y = SENIOR;
            break;
        default:
            break;
    }
}

int graduate(int y) {
    // push them to next year
    y = y + 1;  // enum does not support + _ * // ++
    return y;
}
