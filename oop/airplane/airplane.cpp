#include "airplane.h"
#include <stdexcept>

namespace cs52  {

	Airplane::Airplane( int size ) : mySize( size ),
									myNumberOfPassengersSeenSoFar( 0 ) {
		myPassengers = new Passenger[ mySize ];
	}

	Airplane::~Airplane() {
	#ifdef SHOW_DESTRUCTOR_CALL
		std::cout << ">>> calling ~Airplane() <<<" << std::endl;
	#endif
		delete [] myPassengers;
	}

	int  Airplane::getMaxSize() const {
		return( mySize );
	}

	void Airplane::addPassenger( Passenger p ) {
		if (myNumberOfPassengersSeenSoFar >= getMaxSize()) {
			throw( std::logic_error( "bounds exceeded" ) );
		}
		myPassengers[ myNumberOfPassengersSeenSoFar ] = p;
		myNumberOfPassengersSeenSoFar++;
	}

	std::ostream & operator <<( std::ostream & outs,
								const Airplane * a ) {
		outs << "Airplane- max=" << a->getMaxSize() << std::endl;
		for (int i = 0; i < a->myNumberOfPassengersSeenSoFar; i++) {
			outs << "[" << i << "]-";
			outs << a->myPassengers[ i ];
		}
		return( outs );
	}

}

