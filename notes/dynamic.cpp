// dynamic classes

// destructor           ~Number(); used to clean things up
// intialization list   single ':' handing off the constructor call

int BLUE = 1;

class Number {
    private:
        int *myValue = new int;
        int myColor;
        double myCost;

    public:
        Number(int value);
        ~Number();
};

Number::Number(int value) {
    *myValue = value;
}

// initialization list
// must be same order in class declaration
Number::Number(int value) : myValue(&value),
                            myColor(BLUE),
                            myCost(12.0) {  // single colon ':' only allowed in constructor call
    // empty...
}

int i = 7;
int j(7);

Number::~Number() {
    #ifdef  SHOW_DESTRUCTOR_CALL
        std::cout << ">>> calling ~Number() <<<" << std::endl;
    #endif
        delete [] myValue;
}