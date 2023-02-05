#include <iostream>
#include <string>
using namespace std;

// 1:C_17:2_3:3_4:V

bool isValidSegment(string segment);

// substr(start index, length)
// s.substr(3, 2) -> "_1"

// returns true if parameter is a well-formed order string
bool isValidOrderString(string orders);

// returns total cost for all the order. invalid order string returns -1.00
double cost(string orders);

// count number of combo orders. int whichCombo must be 1, 2, 3. return -1 if anything else.
int howManyCombos(string orders, int whichCombo);

// count number of shake orders. string whichShake must be "Chocolate", "Vanilla", "Strawberry". return -1 if anything else
int howManyShakes(string orders, string whichShake);


int main() {
    
}