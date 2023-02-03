// declare a function named 'scan' that reviews an array of int
// and returns the largest and smallest number in the array.
// hint #1: you'll need to pass an array argument and a companion size parameter.
// hint #2: since you are returning more than one value from your function,
// you'll need to use the reference parameters
// implement this function and then write statements
// to call this functino with an array of size 5.

#include <iostream>
using namespace std;

void scan(int array[], int size, int &largest, int &smallest);

int main() {
    int largest, smallest;

    int a[5] = {6, 2, 3, -7, 5};

    scan(a, 5, largest, smallest);
}

void scan(int array[], int size, int &largest, int &smallest) {
    largest = array[0];
    smallest = array[0];
    for (int i = 0; i < size; i++) {
        // if we see a larger lement, that's our new largest
        if (array[i] > largest) {
            // set largest variable to that element
            largest = array[i];
        }
    }

    for (int i = 0; i < size; i++) {
        if (array[i] < smallest) {
            smallest = array[i];
        }
    }

    cout << "largest: " << largest << endl;
    cout << "smallest: " << smallest << endl;
}