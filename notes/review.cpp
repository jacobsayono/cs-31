#include <string>
#include <cassert>
#include <stdexcept>

// everything we did operated in Stack memory

int main() {
    // automatic variables
    int i;  // lives and dies in main
    double d;
    // almost every single squiggle {} declare start this lifespan
    for (i = 0; i < 10; i++) {
        int value = i + i;  // value dies after exit {}
    }

    for (int j = 0; j < 10; j++) {  // j lives and dies in for loop
        j;
    }

    switch (i) {  // special case, cannot declare variables inside switch/vase
        case 0:
        case 2:
            // int variable = 1;  // not legal
            break;
        case 1:
        case 3:
            break;
    }

    int k = 100;
    int* pointer = nullptr;
    pointer = &k;
    k = 101;
    *pointer = 101;



    // pointer variables work differently with squiggle scope
    int something = foo();
    bar(something);
    // delete pl;

    Candy c = {"M&Ms", "Mars", 1.50};
    Candy e;
    e.mKind = "M&Ms";
    e.mMaker = "Mars";
    e.mCost = 1.50;

    Candy* pCandy = &c;
    pCandy->mKind = "M&Ms";
    (*pCandy).mKind = "M&Ms";



    // ASCII
    // symbols -> numbers -> upper case -> lowercase

    // sorting strings with >, <, ==



    double cost = 123.45;
    assert(cost == 123.45);  // dangerous
    assert(std::to_string(cost) == "123.450000");  // precision of 6 digits to the right of decimal
}

int foo();
int foo() {
    int* pl = new int(100);
    // use variable
    return *pl;
}

void bar(int something);
void bar(int something) {
    // delete pl;
}

class Tire {
    public:
        Tire();
        Tire(int amount);
        void roll(int amount);

        Tire getFrontTire() const;
        void setFrontTire(Tire tire);
    private:
        int mAmount;
};

Tire::Tire() : mAmount(0) {

}

Tire::Tire(int amount) : mAmount(amount) {

}

void Tire::roll(int amount) {

}

Tire Tire::getFrontTire() const {

}

void Tire::setFrontTire(Tire tire) {

}

class Bicycle {
    public:
        Bicycle();
        void ride(int amount);
        double calculateCost() const;
    private:
        Tire mFront;
        Tire mBack;
};

Bicycle::Bicycle() : mFront(1), mBack(1) {
    // by default all the Tires are brand new
}

void Bicycle::ride(int amount) {
    mFront.roll(amount);  // mFront is a Tire type, which can access Tire methods
    mBack.roll(amount);
}

// regular functions cannot be const
// only methods of a class

// const applies what is on its left

double Bicycle::calculateCost() const {
    Bicycle b;
    b.calculateCost();
    // the b does not get changed because of the const
}

struct Candy {
    std::string mKind;
    std::string mMaker;
    double mCost;
};

// function overloading
int fooo(double i);
int fooo(int i);  // OK
// double fooo(double fooo);  // NOT OK



// function parameter passing

// pass bt valye
void foorbar(int i);

// pass by reference
void foorbar(int& i);

// read reference only
void foorbar(const int& i);

// pass array by reference (arrays are pointers by default)
void foorbar(int array[], int size);

// read array reference only
void foobar(const int array[], int size);




enum Weather {CLEAR, RAINY, FOGGY, SNOWY, FROSTY};
//              0      1      2      3       4

enum Student {FRESHMAN = 1, SOPHOMORE = 1, JUNIOR = 50, SENRIOR = 50, MASTER = 100, PHD = 100};

enum Day {MONDAY = 12, TUESDAY, WEDNESDAY = 20, THURSDAY};
//                        13                        21





// topics not on final:
// inheritance, c-strings, exception, exception handling

// topic on final:
// datatypes, variables, functions, parameter passing, pointers, debugger, enum, namespace