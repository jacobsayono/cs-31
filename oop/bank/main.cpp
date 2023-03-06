#include "bank.h"
#include <iostream>
#include <string>
#include <cassert>

int main() {
    // using namespace std;
    using namespace cs31;  // by default, thing called "unnamed" namespace
    // cs31::Bank account1;

    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);

    Bank account1;

    std::string j = "Jacob";
    double jj = 1000;
    Bank account2(j, jj);
    jj = 1234;  // will not change jj because ibalance is private

    std::cout << account1.getName() << std::endl;  // ""
    std::cout << account1.getBalance() << std::endl;  // 0
    
    std::cout << account2.getName() << std::endl;  // "Jacob"
    std::cout << account2.getBalance() << std::endl;  // 1000 NOT 1234

    std::string v = "Vika";
    double vv = 1000;
    account1.setName(v);
    account1.setBalance(vv);
    std::cout << account1.getName() << std::endl;  // "Vika"
    std::cout << account1.getBalance() << std::endl;  // 1000

    double money = 200;
    account1.deposit(money);
    account2.withdraw(money);

    std::cout << account1.getBalance() << std::endl;  // 1200
    std::cout << account2.getBalance() << std::endl;  // 800

    std::string howard = "Howard";
    std::string u = "You";
    double hundred = 100;
    double fifty = 50;
    Bank me(howard, hundred);
    Bank another(howard, fifty);
    Bank you(u, hundred);

    Bank combined = me + another;
    assert(combined.getName() == "Howard");
    assert(combined.getBalance() == 150.00);

    if (me == you) {
        assert(false);
    }
    if (me == me) {
        assert(true);
    }

    Bank less = me - another;
    assert(less.getName() == "Howard");
    assert(less.getBalance() == 50.00);
    std::cin >> less >> std::endl;
    std::cout << less << std::endl;
}