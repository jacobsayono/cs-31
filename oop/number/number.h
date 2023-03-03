#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
#include <cstdlib>

namespace cs31 {

class Number {
public:
	Number();
	Number( int initValue );

	void setValue( int v );
	int  getValue() const;
	// instead of using cout, accept an ostream
	void printRomanNumeral( std::ostream& outs ) const;


private:
	int value;
};


 Number operator + (const Number& left, const Number& right);
 Number operator - (const Number& left, const Number& right);
 bool   operator ==(const Number& left, const Number& right);
 Number operator / (const Number& left, const Number& right);
 Number operator * (const Number& left, const Number& right);

 std::ostream& operator <<(std::ostream& outs, const Number& n);
 std::istream& operator >>(std::istream& ins, Number& n);

}

#endif