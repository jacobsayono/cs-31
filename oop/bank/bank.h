#ifndef BANK_H
#define BANK_H
#include <string>

namespace cs31 {  // good form to put 
    class Bank {
        private:
            std::string name;
            double balance;
        public:
            Bank();
            Bank(std::string iname, double ibalance);

            void setName(std::string iname);
            void setBalance(double ibalance);

            std::string getName() const;  // good form to make getters const
            double getBalance() const;

            void deposit(double ibalance);
            void withdraw(double ibalance);
    };
}

#endif /* BANK_H */