// inheritance - IS-A - "kind of" - "specialization"

// parent
//
// sub class (noun, verb)

// vehical and truck
// vehical and SUV
// vehical and sedan

// every truck is a vehicle, but not every vehicle is a truck

// car
// suburu
// suburu impreza
// red suburu

#include <iostream>
#include <string>

class Car {
    public:
        Car(std::string make, std::string model, std::string color, double price);

        // overrideable operation
        virtual void drive() = 0;  // virtual keyword: "late-binding" dynamic
        // only in .h file

        // make a missing place holder
        // a subclass must provide it
        // abstract operation: feature that needs to be filled in by subclass

        // virtual void drive() = 0;

        // marked with "= 0;" which means the operation is not defined
        // can no longer initialize class Car (abstract class)
        // e.g. Car c("Chevy", "Volt", "Black", 999)
        // but Tesla t(...); and Suburu s(...); can be called

    private:
        std::string mMake, mModel, mColor;
        double mPrice;

};

Car::Car(std::string make, std::string model, std::string color, double price) 
    : mMake(make),  mModel(model), mColor(color), mPrice(price)  // HAS-A
{}

void Car::drive() {
    std::cout << "generic Car drive()" << std::endl;
}




// Suburu class inheritance of Car class
class Suburu: public Car {  // tells c++ suburu and car are related
    public:
        Suburu(std::string model, std::string color, double price);
        virtual void drive();
    private:

};

Suburu::Suburu(std::string make, std::string color, double price)
    : Car("Suburu", make, color, price)
{}

void Suburu::drive() {
    std::cout << "using dead dinosaurs" << std::endl;
}



// inheritance of class Suburu
class SuburuImpreza : public Suburu {
    public:
        SuburuImpreza(std::string color, double price);
    private:

};

SuburuImpreza::SuburuImpreza(std::string color, double price)
    : Suburu("Impreza", color, price)
{}



// inheritance of SuburuImpreza
class RedSuburuImpreza : public SuburuImpreza {
    public:
        RedSuburuImpreza(double price);
    private:

};

RedSuburuImpreza::RedSuburuImpreza(double price)
    : SuburuImpreza("Red", price)
{}








// Tesla class inheritance of Car class
class Tesla : public Car {
    public:
        Tesla(std::string model, std::string color, double price);
        virtual void drive();
    private:

};

Tesla::Tesla(std::string model, std::string color, double price)
    : Car("Tesla", model, color, price)
{}

void Tesla::drive() {
    std::cout << "using electrons" << std::endl;
}








int main() {
    Suburu s("Impreza", "Blue", 1000);
    s.drive();

    Tesla t("X", "Silver", 1111);
    t.drive();

    // cannot do:
    // Car a("Chevy", "Volt", "Black", 999);

    // must do:
    Car* c = nullptr;

    // pointer points to an inheritee
    c = &s;  // change pointing to Suburu s
    c->drive();  // this car uses Suburu's drive()

    c = &t;  // points to Tesla t
    c->drive();  // this car uses Tesla's drive()
    // virtual keyword is expensive in compilation

    return 0;
}




/*
CONCERTE
    tangible
    can create a version of that class
    "real" thing

ABSTRACT
    only ideas, not something we can touch
    some class are "imaginary"
    only for inhertiance purpose...
    an object of that type cannot be made!

e.g.:
ALBERT EINSTEIN

known universe
invented an abstract particle "dark matter"
abstract idea, but cannot put black matter thing into a bowl
*/




/*
cout    #include <iostream>
operator overloading

cout object kinda ostream
be careful ostream
ostream is a class that is missing something
must pass by reference
&ostream

cin object kinda istream
must use &istream also



cout/cin are not really an object of ostream/istream
technically, there is a class called:
istream_with_assign
ostream_with_assign

cout and cin are technically objects of these classes above
and these classes are an inheritance of ostream and istream



istream (abstract)
------------------------------
istream_with_assign (concrete)
cin (object that fill-in abstract and makes class concrete so we can call)
*/