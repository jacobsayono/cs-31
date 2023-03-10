//
//  Move.h
//

#ifndef MOVE_H
#define MOVE_H
#include "Settings.h"
#include "Piece.h"

#include <string>

namespace cs31
{

// The Move object represents a single word play in the Wordle game
// It holds an array of Piece of the required length
// CS 31 students have TODO methods to complete documented below
class Move
{
public:
    // by default, a move will be invalid
    Move();
    
    // TODO create the Pieces for this Move from the supplied word
    // TODO throw logic_error if the supplied word is too short or too long
    void  setPieces( std::string s );
    
    // various different ways to establish one Piece of this Move
    void  setPiece( int i, char c );
    void  setPiece( int i, std::string s );
    void  setPiece( int i, Piece p );
    
    // trivial getter
    Piece getPiece( int i );
    
    // called whenever a Board is displayed
    std::string to_string() const;
    
    bool  isValid( ) const;
    void  random( );
private:
    // the ordered set of Pieces that makeup this Move
    Piece array[ REQUIREDLENGTH ];
};

}

#endif

