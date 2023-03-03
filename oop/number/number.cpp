#include <iostream>
#include <cstdlib>

#include "number.h"
using namespace std;

namespace cs31 {

// note the friend operator functions are not member functions
// note the use of the const modifier
ostream& operator <<( ostream& outs,
					  const Number& n ) {
	n.printRomanNumeral( outs );
	return( outs );
}

istream& operator >>( istream& ins,
					  Number& n ) {
	int i = 0;
	ins >> i;
	n.setValue( i );
	return( ins );
}

Number operator+ ( const Number& left, const Number& right ) {
	Number temp = Number( left.getValue() + right.getValue());
	return( temp );
}

Number operator- ( const Number& left, const Number& right ) {
	Number temp = Number(left.getValue() - right.getValue());
	return( temp );
}

Number operator/ ( const Number& left, const Number& right ) {
	Number temp = Number(left.getValue() / right.getValue());
	return( temp );
}

Number operator* ( const Number& left, const Number& right ) {
	Number temp = Number(left.getValue() * right.getValue());
	return( temp );
}

bool operator== ( const Number& left, const Number& right ) {
	return(left.getValue() == right.getValue());
}

Number::Number() {
	value = 0;
}

Number::Number( int initValue ) {
	value = initValue;
}

void Number::setValue( int v ) {
	value = v;
}

// note the use of the const modifier
int  Number::getValue() const {
	return( value );
}

// note the use of the const modifier
void Number::printRomanNumeral( std::ostream& outs ) const {
	// uses cout
	using namespace std;
	int remainder = value;
	int thousands = remainder / 1000;
	remainder -= thousands * 1000;
	int fivehundreds = remainder / 500;
	remainder -= fivehundreds * 500;
	int hundreds = remainder / 100;
	remainder -= hundreds * 100;
	int fiftys = remainder / 50;
	remainder -= fiftys * 50;
	int tens = remainder / 10;
	remainder -= tens * 10;
	int fives = remainder / 5;
	remainder -= fives * 5;
	int ones = remainder;

	int i;

	for (i = 1; i <= thousands; ++i)
		outs << "M";
	if (fivehundreds == 1 && hundreds == 4) {
		outs << "CM";
		fivehundreds = 0;
		hundreds = 0;
	}
	for (i = 1; i <= fivehundreds; ++i)
		outs << "D";
	if (hundreds == 4) {
		outs << "CD";
		hundreds = 0;
	}
	for (i = 1; i <= hundreds; ++i)
		outs << "C";
	if (fiftys == 1 && tens == 4) {
		outs << "XC";
		fiftys = 0;
		tens = 0;
	}
	for (i = 1; i <= fiftys; ++i)
		outs << "L";
	if (tens == 4) {
		outs << "XL";
		tens = 0;
	}
	for (i = 1; i <= tens; ++i)
		outs << "X";
	if (fives == 1 && ones == 4) {
		outs << "IX";
		ones = 0;
		fives = 0;
	}
	for (i = 1; i <= fives; ++i)
		outs << "V";
	if (ones == 4) {
		outs << "IV";
		ones = 0;
	}
	for	(i = 1; i <= ones; ++i)
		outs << "I";
	outs << endl;
}


}
