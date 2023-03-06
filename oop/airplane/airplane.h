#ifndef AIRPLANE_H
#define AIRPLANE_H
#include "passenger.h"

// uncomment to show destructor call
// #define SHOW_DESTRUCTOR_CALL

namespace cs52  {

	class Airplane {
		public:
			Airplane( int size = 100 );
			~Airplane();

			void addPassenger( Passenger p );
			int  getMaxSize() const;
			friend std::ostream & operator <<( std::ostream & outs,
											const Airplane * a );

		private:
			// every airplane is potentially a different size
			int mySize;
			Passenger * myPassengers;   // a dynamic array
			int myNumberOfPassengersSeenSoFar;
	};

}

#endif