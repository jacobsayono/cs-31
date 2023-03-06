#include "passenger.h"

namespace cs52 {

	Passenger::Passenger( std::string n ) : myName( n ) {
	}

	// Passenger::Passenger(std::string n) {
	// 	n = myName;
	// }

	std::string Passenger::getName() const {
		return( myName );
	}

	void Passenger::setName( std::string n ) {
		myName = n;
	}

	std::ostream & operator <<( std::ostream & outs,
								const Passenger & p ) {
		outs << p.myName << std::endl;
		return( outs );
	}

}