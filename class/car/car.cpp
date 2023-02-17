// c++ class
// blueprint for a type... like a struct
// advanced features...

// data AND operations
// fields plus functions

// Car
// data - Make      Model
//        Honda     Prelude
// operations - "what" a class "knows" to do
//              insertKey, turn, drive, honk, stop
//              "verbs" or "actions"
// multi-file projects...
// create class.h     declaration:  what a Car is
//        class.cpp   implemantation: main driver code

#include <iostream>
#include "car.h"
using namespace std;

Car::Car() {
    mMake = "dummy make";
    mModel = "dummy model";
}

Car::Car(string make, string model) {
    mMake = make;
    mModel = model;
}

// scoping start() to class Car
void Car::start() {
    cout << "drive" << endl;
}

void Car::drive() {
    cout << "start" << endl;
}

void Car::stop() {
    cout << "stop" << endl;
}

void Car::honk() {
    cout << "honk" << endl;
}