//
//  Move.cpp
//

#include "Move.h"
#include "Random.h"
#include <stdexcept>

namespace cs31
{

// by default, a move is invalid
Move::Move()
{
    // this code is really not needed since the default constructor
    // will do all this work but I am explicitly showing it for CS 31
    // students
    Piece p;  // invalid piece
    array[ 0 ] = p;
    array[ 1 ] = p;
    array[ 2 ] = p;
    array[ 3 ] = p;
}

// trivial getter
// but throw logic_error if the index is out of range
Piece Move::getPiece( int i )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        return( array[ i ] );
    else
        throw std::logic_error( "invalid i value" );
}

// construct a Piece for the Move from the character parameter
// but throw logic_error if the index is out of range
void  Move::setPiece( int i, char c )
{
    if (i >= 0 && i < REQUIREDLENGTH)
    {
        Piece p( c );
        array[ i ] = p;
    }
    else
        throw std::logic_error( "invalid i value" );
}

// construct a Piece for the Move from the Piece parameter
// but throw logic_error if the index is out of range
void  Move::setPiece( int i, Piece p )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        array[ i ] = p;
    else
        throw std::logic_error( "invalid i value" );
}

// construct a Piece for the Move from the first letter
// of the string parameter
// but throw logic_error if the index is out of range
void  Move::setPiece( int i, std::string s )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        setPiece( i, s.at( 0 ) );
    else
        throw std::logic_error( "invalid i value" );
}

// TODO create the Pieces for this Move from the supplied word
// TODO throw logic_error if the supplied word is too short or too long
void  Move::setPieces( std::string s )
{
    // for now...
    // check that the length of string is 4, if not throw logic_error
    if (s.length() != REQUIREDLENGTH) {
        throw std::logic_error("not 4-characters long");
    }
    // iterate through the string and set each char to the element of array
    for (int i = 0; i < REQUIREDLENGTH; i++) {
        array[i] = s.at(i);
    }
}

// stringify this Move
std::string Move::to_string() const
{
    std::string s;
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        s += array[ i ].getColorAsString();
    }
    return( s );
}

bool  Move::isValid( ) const
{
    bool result( true );
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        if (array[i].getColor() == NOTVALID)
        {
            result = false;
        }
    }
    return( result );
}

void  Move::random()
{
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        Random r( VALIDCOLORCOUNT - 1 );
        r.random();
        COLOR c = static_cast< COLOR > ( r.getValue() );
        Piece p( c );
        array[ i ] = p;
    }
}

}

