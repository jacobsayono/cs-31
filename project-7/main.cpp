//
//  main.cpp
//  Mastermind
//
//  Created by Howard Stahl on 9/21/22.
//

#include <iostream>
#include "Random.h"
#include "Piece.h"
#include "Board.h"
#include "Score.h"
#include "Settings.h"
#include "Enums.h"
#include "Mastermind.h"


int main( ) {
    using namespace cs31;
    using namespace std;

//  Choose a random answer...
    Mastermind game;
    bool forceEnd = false;
    std::string action, turn, message = "(p)lay (q)uit: ";
    cout << game.display( message ) << endl;
    
    do
    {
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                forceEnd = true;
                break;
            case 'p':
            case 'P':
                if (game.determineGameOutcome() == GAMENOTOVER)
                {
                    getline( cin, turn );
                    Move m = game.play( turn );
                    
                    if (m.isValid())
                    {
                        Score s = game.endRound(m);
                        s.isExactMatch();  // just to avoid warning...
                    }
                    else
                    {
                        // turn was not a valid word
                        cout << turn << " was not a Mastermind game entry!" << endl;
                    }
                }
                break;
        }
        if (!game.gameIsOver())
        {
            cout << game.display( message ) << endl;
        }
        else
        {
            cout << game.display( game.gameOutcomeAsString() ) << endl;
            cout << "The winning Mastermind game entry was: " << game.answer() << endl;
        }
    } while( !game.gameIsOver() && !forceEnd );

    
    
    
    return( 0 );
}
