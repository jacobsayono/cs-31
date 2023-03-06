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
            Bank(std::string &iname, double &ibalance);
            Bank(double &ibalance);

            void setName(std::string &iname);
            void setBalance(double &ibalance);

            std::string getName() const;  // good form to make getters const
            double getBalance() const;

            void deposit(double &ibalance);
            void withdraw(double &ibalance);

            // operator overload
            friend Bank operator +(const Bank &left, const Bank &right);
            friend Bank operator -(const Bank &left, const Bank &right);
            friend bool operator ==(const Bank &left, const Bank &right);
            friend std::ostream& operator <<(std::ostream& outs, const Bank& balance);
            friend std::istream& operator >>(std::istream& ins, const Bank& balance);
    };
}

#endif /* BANK_H */