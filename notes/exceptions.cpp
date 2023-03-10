#include <iostream>
#include <stdexcept>

void check(double balance);
// void checker(double balance) throw(std::logic_error, std::runtime_error);

int main() {
    // std::logic_error e("bad news");  // pass a string
    // throw e;

    double balance = -1;

    try {
        check(balance);
    }
    // catch (const std::logic_error& e) {
    catch (std::logic_error le) {
        std::cerr << "recover statement: " << le.what() << std::endl;
    }
}

void check(double balance) {
    if (balance < 0) {
        // std::string e = "no negative balances allowed";
        // // std::string e = "no negative balances allowed";
        // throw std::logic_error(e);
        std::logic_error e ("error msg");
        throw e;
    }
}

// void checker(double balance) throw(std::logic_error, std::runtime_error) {

// }

// warning: dynamic exception specifications are deprecated in C++11