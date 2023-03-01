// heap memory
// use 'new' and 'delete'
// dynamic arrays
#include <string>
#include <iostream>
#include <cstring>

class bankAccount {
        public:
            bankAccount(std::string name, double balance);
            void deposit(double amount);
            void withdraw(double amount);
        private:
            std::string name;
            double balance;
    };

bankAccount::bankAccount(std::string name, double balance) {
    std::string name = "lol";
    double balance = 100;
}

void bankAccount::deposit(double amount) {
    balance += amount;
}

void bankAccount::withdraw(double amount) {
    balance -= amount;
}


int main() {
    int* ptr = nullptr; // ptr points to nothing

    // allocate heap memory
    ptr = new int(12);
    *ptr = 13;

    // run a bunch of code
    // clean things up

    delete ptr;

    bankAccount you("You", 1000);
    bankAccount* ptrYou = &you;
    you.deposit(10);
    (*ptrYou).deposit(10);
    ptrYou->deposit(10);  // operator -> "arrow"

    // ptrYou -----> |"You", 1000|
    //                     you

    bankAccount* newAccount = new bankAccount("Me", 100.00);
    newAccount->withdraw(50);
    delete(newAccount);

    // array needs a known size during compile time
    // int i;
    // cin >> i;
    // string a[i];  // ILLEGAL

    int i;
    std::cin >> i;
    std::string* array = new std::string[i];  // dynamic array
    // for this line above to build and run correctly
    // public default no argument constructor
    // string()
    array[0] = "a";
    array[1] = "b";
    array[2] = "c";
    array[3] = "d";
    array[4] = "e";

    // we can offset into the array without using [] brackets
    array[0] = "AAA";
    // same thing done:
    *array = "AAA";

    // same 2 lines
    array[1] = "BBB";
    *(array + 1) = "BBB";

    std::string* address = array;  // address is spot 0;
    // same 2 lines
    array[2] = array[1];  // copying "BBB" into spot 2
    *(address + 2) = *(array + 1);

    address++;
    address--;

    // deallocate heap memory
    delete[] array;  // something you new'd with square brackets


    // str ---> |a|b|c|d|\0|
    // draw out is called char* (c programmer uses this to represent)
    // char*    NULL terminated array of char  NULL is a marker "sentinal"
    char str[] = "abcd";
    char* s = new char[5];
    strcpy(s, "abcd");  // #include <cstring>
    char sameThing[5] = {'a', 'b', 'c', 'd', '\0'};

    delete[] s;

    // cstring vs array
    char v[] = "abc";  // initializer, not an assignment statement
    char w[] = {'a', 'b', 'c'};

    // char x[5]; 
    // x = "Foo";  // will not build

    char y[5] = "Foo";  // must do this way

    // you can use an index to walk the array
    char lots_of_x[] = "hello world";
    int index = 0;
    while (lots_of_x[index] != '\0') {
        lots_of_x[index] = 'x';
        index++;
    }

    // string class
    // .length()
    // .at()
    // constructor:
    // string dog("dog");
    // string dog = "dog";
}