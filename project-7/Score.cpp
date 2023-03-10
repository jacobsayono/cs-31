//
//  Score.cpp
//

#include "Score.h"
#include <stdexcept>

namespace cs31
{

// setup a default score - all WRONG ANSWER's
Score::Score()
{
    for( int i = 0; i < REQUIREDLENGTH; i++ )
    {
        array[ i ] = WRONG;
    }
}

// TODO comparing the played move to the answer move,
//      build the ANSWER array of this Score
Score::Score( Move move, Move answer )
{
    // for now...
}

// trivial getter but throw logic_error if the index is out of range
ANSWER Score::getAnswer( int i )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        return( array[ i ] );
    else
        throw std::logic_error( "invalid i value" );
}

// stringify this Score
std::string Score::to_string() const
{
    std::string s = "";
    int mCount = 0;
    int rCount = 0;
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        switch( array[i] )
        {
            case WRONG:
                // wrongs should not be printed at all
                s += "_";
                break;
            case RIGHT:
                rCount++;
                s += "R";
                break;
            case MAYBE:
                mCount++;
                s += "M";
                break;
        }
    }
    return( s );
}

// TODO is the ANSWER array all RIGHT ANSWER's?
bool Score::isExactMatch() const
{
    // for now..
    return( false );
}

}

