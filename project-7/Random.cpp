//
//  Random.cpp
//

#include "Random.h"
#include <random>

namespace cs31
{
    // at constructor time, the client specifies the desired maximum value
    Random::Random( int maxValue ) : mMaxValue( maxValue )
    {

    }
    
    // generate and save a random number
    void Random::random()
    {
        std::random_device rd;
        std::mt19937 e2(rd());
        std::uniform_int_distribution<> dist(0, mMaxValue);
        mValue = dist(e2);
    }
    
    // retrieve the previously generated random number
    int  Random::getValue( ) const
    {
        return( mValue );
    }

}

