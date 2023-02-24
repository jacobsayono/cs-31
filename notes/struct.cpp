#include <iostream>
#include "struct.h"
using namespace std;

int main() {
    // int b;
    Book b;
    Book b1;
    Book b2;

    // get the fields using '.'
    b.mAuthor = "Some Guy Named Howard";
    b.mTitle = "Cold Mountain Creek";
    b.mJacketColor = BLACK;
    b.mNumberOfPages = 800;
    b.mNumberOfPages = b.mNumberOfPages + 100;

    // calculations
    // first quarter of the book is chapter 1
    int chapter1 = b.mNumberOfPages / 4;

    b1.mAuthor = "JK Rowlings";
    b1.mTitle = "Harry Potter";

    // every field of a structure is publicly open to code
}