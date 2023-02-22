#include "bank.h"
#include <iostream>
#include <string>

int main() {
    // using namespace std;
    using namespace cs31;  // by default, thing called "unnamed" namespace
    // cs31::Bank account1;

    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);

    Bank account1;
    Bank account2("Jacob", 1000);

    std::cout << account1.getName() << std::endl;  // ""
    std::cout << account1.getBalance() << std::endl;  // 0
    
    std::cout << account2.getName() << std::endl;  // "Jacob"
    std::cout << account2.getBalance() << std::endl;  // 1000

    account1.setName("Vika");
    account1.setBalance(1000);
    std::cout << account1.getName() << std::endl;  // "Vika"
    std::cout << account1.getBalance() << std::endl;  // 1000

    account1.deposit(200);
    account2.withdraw(200);

    std::cout << account1.getBalance() << std::endl;  // 1200
    std::cout << account2.getBalance() << std::endl;  // 800
}