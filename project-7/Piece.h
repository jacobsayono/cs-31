//
//  Piece.h
//

#ifndef PIECE_H
#define PIECE_H

#include <string>
#include "Enums.h"

namespace cs31
{

// This class represents a single letter played in Wordle
// and works with the LETTER enumeration
// This class is completely finished
// CS 31 students have no work to do here
class Piece
{
public:
    // by default, a Piece will be invalid
    Piece();
    // build a Piece based on the COLOR parameter
    Piece( COLOR color );
    // build a Piece based on the character parameter
    Piece( char c );
    // build a Piece based on the first letter of the string parameter
    Piece( std::string s );
    
    // trivial getter
    COLOR getColor() const;
    // convert the COLOR into its string representation
    std::string  getColorAsString() const;
private:
    COLOR mColor;
    
    void  pickColor( char c );
};

}

#endif

