//
//  Board.h
//

#ifndef BOARD_H
#define BOARD_H

#include "Move.h"
#include "Score.h"
#include "Settings.h"
#include <string>

namespace cs31
{
    // The Board object is repetitively displayed as the
    // Wordle game progresses
    // It holds an array of Moves and Scores fed to it with calls to
    // endRound that get printed later with a call to display
    // CS 31 students have TODO methods to complete documented below
    class Board
    {
    public:
        Board();
        // save this Move and Score which will get printed later
        void endRound( Move m, Score s );
        
        // TODO trivial getter
        int getCurrentRound() const;
        // TODO acquire a Move for a particular round of play
        // TODO throw logic_error if the round is invalid or
        //                        if the round has not yet been played
        Move getMoveForRound( int round ) const;
        // TODO acquire a Move for a particular round of play
        // TODO throw logic_error if the round is invalid or
        //                        if the round has not yet been played
        Score getScoreForRound( int round ) const;
        
        // print this Board
        std::string display( ) const;
    private:
        // the current round of play so far
        int mRoundCount;
        // set of scores provided to this Board so far
        Score scores[ TOTALROUNDSALLOWED ];
        // set of moves provided to this Board so far
        Move  moves[ TOTALROUNDSALLOWED ];
    };
}

#endif

