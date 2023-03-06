#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>

namespace cs52 {

	class Passenger {
		public:
			Passenger( std::string n = "" );

			std::string getName() const;
			void setName( std::string n );

			friend std::ostream & operator <<( std::ostream & outs,
											   const Passenger & p );

		private:
			std::string myName;
	};

}

#endif