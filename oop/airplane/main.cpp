#include <string>
#include <iostream>
#include "airplane.h"
#include "passenger.h"

enum MENU { PRINT, QUIT, ADDPASSENGER, NEWPLANE };
MENU menu();

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
			cin  >> size;
			// throw away the existing airplane...
			delete( a );
			a = new Airplane( size );
			break;
		case PRINT:
			cout << a;
			break;
		case ADDPASSENGER:
			cout << "Gimme a passenger name:";
			cin >> name;
			Passenger p( name );
			try {
				a->addPassenger( p );
			} catch( std::logic_error le ) {
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
		result = menu();
		break;
	}
	return( result );
}
