#include <string>
#include <iostream>
#include "airplane.h"
#include "passenger.h"

enum MENU { PRINT, QUIT, ADDPASSENGER, NEWPLANE };
MENU menu();  // returns PRINT, QUIT, ADDPASSENGER, or NEWPLANE

int main() {
	using namespace cs52;
	using namespace std;

	// Here's the airplane we will fool around with...
	Airplane * a = NULL;
	int size = 0;
	Passenger p;
	std::string name;
	MENU choice = QUIT;
	do {
		choice = menu();
		switch( choice ) {
        case QUIT:
            break;
		case NEWPLANE:
			cout << "How big a plane do you want? ";
			cin  >> size;  // int
			// throw away the existing airplane...
			delete( a );
			a = new Airplane( size );  // mySize = size, myNumberofPassengersSeenSoFar = 0, myPassengers = new Passenger[mySize]
			break;
		case PRINT:
			cout << a;
			// ostream& operator <<(ostream& outs, Airplane* a)
			// return mySize accessed from getMaxSize()
			// iterate from index 0 to myNumberOfPassengersSeenSoFar
			// outs << index number i
			// outs << myPassengers[i]
			// attribute AirPlane::myPassengers = new (class) Passenger[mySize] <--- initialized at max size
			// which is Passenger::myName
			break;
		case ADDPASSENGER:
			cout << "Gimme a passenger name:";
			cin >> name;
			Passenger p( name );  // myName = name
			try {
				a->addPassenger( p );
				// airplaine is a pointer object, accessing addPassenger method
				// ---> myPassengers[myNumberofPassengersSeenSoFar] = object p
				// ---> which is the name of the passenger p(name)
				// and add index myNumberOfPassengersSeenSoFar +1
			} catch( std::logic_error le ) {  // throw(std::logic_error("bounds exceeded"))
				cout << "addPassenger was refused... plane is full!" << endl;
			}
			break;
		}
	} while (choice != QUIT);
    return( 0 );
}

MENU menu() {
	using namespace std;
	MENU result = QUIT;
	char c;
	cout << "(N)ewPlane (A)ddPassenger (P)rint (Q)uit:";
	cin >> c;
	switch( c ) {
	case 'N':
	case 'n':
		result = NEWPLANE;
		break;
	case 'A':
	case 'a':
		result = ADDPASSENGER;
		break;
	case 'P':
	case 'p':
		result = PRINT;
		break;
	case 'Q':
	case 'q':
		result = QUIT;
		break;
	default:
		result = menu();  // "try again"
		break;
	}
	return( result );
}
