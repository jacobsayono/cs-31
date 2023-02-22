#include "bank.h"
#include <string>

namespace cs31 {
    Bank::Bank() {
        name = "";
        balance = 0;
    }

    Bank::Bank(std::string iname, double ibalance) {
        name = iname;
        balance = ibalance;
    }

    void Bank::setName(std::string iname) {
        name = iname;
    }

    void Bank::setBalance(double ibalance) {
        balance = ibalance;
    }

    std::string Bank::getName() const {
        return name;
    }

    double Bank::getBalance() const {
        return balance;
    }

    void Bank::deposit(double ibalance) {
        balance += ibalance;
    }

    void Bank::withdraw(double ibalance) {
        balance -= ibalance;
    }
}