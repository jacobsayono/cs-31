// window dressing yuck to get c++ to work right
// guard our .h to read only once

#ifndef CAR_H  // if CAR_H not defined, can named anything. if already defined, skip all this code
#define CAR_H  // give CAR_H name a value, flip from 0 to 1. CAR_H ===> 1
// #pragma once  // VS only

#include <string>

class Car {
    // supports "information hiding"
    // public, private
    // follow a good pattern:
    // operations are public
    // data are private

    // operations   WHAT it does, NOT HOW it does it
    public:  // open to everyone, e.g.: driver code
        // constructor (name exactly matches the class itself)
        // constructor helps set up the data members
        Car(std::string make, std::string model);
        
        // if no constructors defined, c++ automatically creates a no-argument constructor
        // usually we make multiple constructors

        // if we make a constructor, the free no-argument constructor will not exist
        Car();
        // constructors can be marked private (rare and not in this course)


        // functions
        void start();
        void drive();
        void stop();
        void honk();

    // data
    private:  // locked away, only class itself NOT driver code
        std::string mMake;
        std::string mModel;
};

#endif  // basically, guards the file to be only read once