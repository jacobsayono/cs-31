#include <string>

using namespace std;

class Address {
    public:
        Address();
        Address(string streetnumber, string street, string city, string state, string zip);
        string getStreetNumber();
        string getStreet();
        string getCity();
        string getState();
        string getZip();
    private:
        string mStreetNumber;
        string mStreet;
        string mCity;
        string mState;
        string mZip;
};

class bankAccount { 
    public:  // class member functions 
        //--constructors 
        bankAccount(); 
        
        bankAccount(string initName, double initBalance, Address initAddress); 
        // post: A bankAccount with two arguments when called like this: 
        //       bankAccount anAcct("Hall", 100.00); 
        
        //--modifiers 
        
        void deposit(double depositAmount); 
        // post: depositAmount is credited to this object's balance 
        
        void withdraw(double withdrawalAmount); 
        // post: withdrawalAmount is debited from this object's balance 
        
        //--accessors 
        
        double balance() const; 
        // post: return this account's current balance 
        
        string name() const; 
            // post return the account name 
        
        void setName( string initName ); 
        // post updates the member variable my_name 
    
    private:  
        string my_name;    // Uniquely identify an object 
        double my_balance; // Store the current balance 
        Address my_address;
}; 





 
//--constructors 
 
bankAccount::bankAccount() 
{  
    my_name = "?name?"; 
    my_balance = 0.0;
} 
 
bankAccount::bankAccount(string initName, double initBalance, Address initAddress) 
{ 
    my_name = initName; 
    my_balance = initBalance;
    my_address = initAddress;
} 
 
//--modifiers 
 
void bankAccount::deposit(double depositAmount) 
{ 
    my_balance = my_balance + depositAmount; 
} 
 
void bankAccount::withdraw(double withdrawalAmount) 
{ 
    my_balance = my_balance - withdrawalAmount; 
} 
 
//--accessors 
 
double bankAccount::balance() const 
{ 
    return my_balance; 
} 
 
string bankAccount::name() const 
{ 
    return my_name; 
} 
 
void bankAccount::setName( string initName ) 
{ 
    my_name = initName; 
} 
 
 
 
 
 
 
 


Address::Address() {}

Address::Address(string streetnumber, string street, string city, string state, string zip) :
    mStreetNumber(streetnumber),
    mStreet(street),
    mCity(city),
    mState(state),
    mZip(zip)
{}

string Address::getStreetNumber() {
    return mStreetNumber;
}

string Address::getStreet() {
    return mStreet;
}

string Address::getCity() {
    return mCity;
}

string Address::getState() {
    return mState;
}

string Address::getZip() {
    return mZip;
}

int main() {}