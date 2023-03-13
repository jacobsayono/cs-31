//
//  main.cpp
//  Mastermind
//
//  Created by Howard Stahl on 9/21/22.
//

#include <iostream>
#include <cassert>
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

    // test code
    Piece p;
    assert( p.getColor() == NOTVALID );
    p = Piece( "R" );
    assert( p.getColor() == RED );
    assert( p.getColorAsString() == "R" );

    Move m;
    p = m.getPiece( 0 );
    assert( p.getColor() == NOTVALID );
    m.setPieces( "RBRB" );
    p = m.getPiece( 2 );
    assert( p.getColor() == RED );
    m.setPiece( 2, 'y' );
    p = m.getPiece( 2 );
    assert( p.getColor() == YELLOW );

    Score s;
    assert( s.isExactMatch()  == false );
    assert( s.getAnswer( 2 ) == WRONG );
    m.setPieces( "RBRB" );

    Move mM;
    mM.setPieces( "OYOY" );

    Move mR;
    mR.setPieces("YOYO");
    Move theAnswer;
    theAnswer.setPieces( "YOYO" );
    s = Score( m, theAnswer );

    Score sM;
    sM = Score(mM, theAnswer);
    Score sR;
    sR = Score(mR, theAnswer);

    // cout << s.to_string() << endl;
    // cout << "here" << endl;
    assert( s.isExactMatch() == false );
    // cout << s.to_string() << endl;

    // wrong case
    assert( s.to_string() == "____" );
    theAnswer.setPieces( "rbrb" );
    s = Score( m, theAnswer );
    assert( s.isExactMatch() == true );

    // right case
    assert( s.to_string() == "RRRR" );
    assert(sR.to_string() == "RRRR" );

    // maybe case
    assert(sM.to_string() == "MMMM");

    
    Move m1;
    m1.setPieces("GGPP");
    Move a1;
    a1.setPieces("GGPP");
    Score s1(m1, a1);
    cout << s1.to_string() << endl;

    Move m2;
    m2.setPieces("GPOB");
    Move a2;
    a2.setPieces("GOPB");
    Score s2(m2, a2);
    cout << s2.to_string() << endl;

    Move m3;
    m3.setPieces("GGOP");
    Move a3;
    a3.setPieces("OPGG");
    Score s3(m3, a3);
    cout << s3.to_string() << endl;

    Move m4;
    m4.setPieces("GGOP");
    Move a4;
    a4.setPieces("BYBY");
    Score s4(m4, a4);
    cout << s4.to_string() << endl;

    Move m5;
    m5.setPieces("GGOP");
    Move a5;
    a5.setPieces("OPGY");
    Score s5(m5, a5);
    cout << s5.to_string() << endl;

    Move m6;
    m6.setPieces("GGOP");
    Move a6;
    a6.setPieces("POGB");
    Score s6(m6, a6);
    cout << s6.to_string() << endl;

    Move m7;
    m7.setPieces("GGYY");
    Move a7;
    a7.setPieces("YBGB");
    Score s7(m7, a7);
    cout << s7.to_string() << endl;

    Move m8;
    m8.setPieces("GGGY");
    Move a8;
    a8.setPieces("YGGB");
    Score s8(m8, a8);
    cout << s8.to_string() << endl;


    cout << endl;

    // more stuff
    Move m99;
    m99.setPieces("YBOB");
    Move m88;
    m88.setPieces("OOOO");
    Move m77;
    m77.setPieces("OOYO");

    Score s99;
    s99 = Score(m99, theAnswer);
    Score s88;
    s88 = Score(m88, theAnswer);
    Score s77;
    s77 = Score(m77, theAnswer);

    cout << s99.to_string() << endl;
    cout << s88.to_string() << endl;
    cout << s77.to_string() << endl;
    assert(s99.to_string() == "R_R_");
    assert(s88.to_string() == "_R_R");
    assert(s77.to_string() == "_RRR");



    Board b;
    assert( b.getCurrentRound() == 0 );
    m.setPieces( "POPO" );
    theAnswer.setPieces( "YYOP" );
    s = Score( m, theAnswer );
    b.endRound( m, s );
    assert( b.getCurrentRound() == 1 );
    assert( b.getMoveForRound( 0 ).to_string() == "POPO" );
    assert( b.getScoreForRound( 0 ).to_string() == "MM__" );

    Mastermind game1( "rbyo" );
    assert( game1.answer() == "RBYO" );
    assert( game1.gameIsOver() == false );
    m = game1.play( "BBBB" );
    s = game1.endRound( m );
    assert( s.to_string() == "_R__" );

    cout << "all tests passed!" << endl;

    
    
    return( 0 );
}
