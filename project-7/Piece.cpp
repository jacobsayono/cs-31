//
//  Piece.cpp
//

#include "Piece.h"

namespace cs31
{

// by default, a Piece is invalid
Piece::Piece() : mColor(NOTVALID)
{
}

// build a Piece based on the COLOR parameter
Piece::Piece( COLOR color )
{
    mColor = color;
}

// build a Piece based on the character parameter
Piece::Piece( char c )
{
    pickColor( c );
}

// build a Piece based on the first letter of the string parameter
Piece::Piece( std::string s )
{
    // don't walk off the end of the string...
    if (s.length() > 0)
    {
        pickColor( s.at( 0 ) );
    }
}

void  Piece::pickColor( char c )
{
    switch( c )
    {
        case 'B':
        case 'b':
            mColor = BLUE;
            break;
        case 'G':
        case 'g':
            mColor = GREEN;
            break;
        case 'O':
        case 'o':
            mColor = ORANGE;
            break;
        case 'P':
        case 'p':
            mColor = PURPLE;
            break;
        case 'R':
        case 'r':
            mColor = RED;
            break;
        case 'Y':
        case 'y':
            mColor = YELLOW;
            break;

        default:
            mColor = NOTVALID;
            break;
    }
}


COLOR Piece::getColor() const
{
    return( mColor );
}

std::string  Piece::getColorAsString() const
{
    std::string s;
    switch( mColor )
    {
        case BLUE:
            s = "B";
            break;
        case GREEN:
            s = "G";
            break;
        case ORANGE:
            s = "O";
            break;
        case PURPLE:
            s = "P";
            break;
        case RED:
            s = "R";
            break;
        case YELLOW:
            s = "Y";
            break;

        default:
            s = " ";
            break;
    }
    return( s );

}

}

