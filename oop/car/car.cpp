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

Car::Car() {
    mMake = "dummy make";
    mModel = "dummy model";
}

Car::Car(std::string make, std::string model) {
    mMake = make;
    mModel = model;
}

// scoping start() to class Car
void Car::start() {
    std::cout << "drive" << std::endl;
}

void Car::drive() {
    std::cout << "start" << std::endl;
}

void Car::stop() {
    std::cout << "stop" << std::endl;
}

void Car::honk() {
    std::cout << "honk" << std::endl;
}