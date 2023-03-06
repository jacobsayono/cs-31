#include "bank.h"
#include <string>
#include <iostream>

namespace cs31 {
    // constructors
    Bank::Bank() {
        name = "";
        balance = 0;
    }

    Bank::Bank(std::string &iname, double &ibalance) {
        name = iname;
        balance = ibalance;
    }

    Bank::Bank(double &ibalance) {
        balance = ibalance;
    }

    // accessors (getters and setters)
    void Bank::setName(std::string &iname) {
        name = iname;
    }

    void Bank::setBalance(double &ibalance) {
        balance = ibalance;
    }

    std::string Bank::getName() const {
        return name;
    }

    double Bank::getBalance() const {
        return balance;
    }

    // modifiers
    void Bank::deposit(double &ibalance) {
        balance += ibalance;
    }

    void Bank::withdraw(double &ibalance) {
        balance -= ibalance;
    }

    // operator overload
    Bank operator +(const Bank &left, const Bank &right) {
        // if Bank(double ibalance) <- pass by value:
        // Bank sum = Bank(left.balance + right.balance);
        // return sum;
        // but Bank(double& ibalance) <- pass by reference:
        double sum = left.balance + right.balance;
        // return Bank(sum);
        std::string combined_name = left.name;
        return Bank(combined_name, sum);
    }

    Bank operator -(const Bank &left, const Bank &right) {
        double diff = left.balance - right.balance;
        std::string combined_name = left.name;
        return Bank(combined_name, diff);
    }

    bool operator ==(const Bank &left, const Bank &right) {  // check for same name
        return (left.name == right.name);
    }

    // assume format is "NAME: $DOLLAR.CENTS"
    // e.g. "Jacob: $123.45"
    std::ostream& operator <<(std::ostream& outs, const Bank& account) {
        std::string account_name = account.name;
        outs << account_name;
        std::string colon_space = ": $";
        outs << colon_space;
        double account_balance = account.balance;
        outs << account_balance;

        // can just do:
        // outs << account.name << ": " << account.balance;
        // if parameters were not passed by reference
        return outs;
    }

    std::istream& operator >>(std::istream& ins, Bank& account) {
        // name
        std::string account_name;
        ins >> account_name;
        int name_size = account_name.size();
        if (account_name[name_size - 1] != ':') {
            std::cout << "error, no ':' separator" << std::endl;
            exit(1);
        }
        
        account.setName(account_name);
        // why is this inaccessible even though operator>> is a friend function?
        // account.name = account_name;

        char space;
        ins >> space;
        if (space != ' ') {
            std::cout << "error, no ' ' separator'" << std::endl;
            exit(1);
        }

        // money
        char dollar_sign;
        ins >> dollar_sign;
        if (dollar_sign != '$') {
            std::cout << "error, no '$' separator" << std::endl;
            exit(1);
        }

        double bal;
        ins >> bal;

        account.deposit(bal);
        // account.balance = bal;

        return ins;
    }
}