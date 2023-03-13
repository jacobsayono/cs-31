//
//  Score.cpp
//

#include "Score.h"
#include <stdexcept>
#include <iostream>
using namespace std;

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
    for( int i = 0; i < REQUIREDLENGTH; i++ )
    {
        array[i] = WRONG;  // first case scenerio, set everything to WRONG and start changing them when each conditions below checks out
        // cout << "W" << endl;
    }

    // iterate through each piece in the "move" array (4 total)
    for (int i = 0; i < REQUIREDLENGTH; i++) {
        // OBJECT (INSTANTIATED), ATTRIBUTE (PRIVATE), METHOD (PUBLIC), CONSTANT
        // object.method()
        // attribute.method()
        // constant exists at the bottom of the hierarchy, which gets returned at last

        // move [instantiated OBJECT of type class-Move] ---> that accesses:
        // Move::getPiece() [METHOD of type class-Piece] ---> that returns:
        // Piece::getColor() [METHOD of type enum-COLOR] ---> that returns:
        // COLOR::RED [CONSTANT of type integral]

        COLOR move_colors = move.getPiece(i).getColor();  // color at index i of "move" array
        COLOR answer_colors = answer.getPiece(i).getColor();
        
        if (move_colors == answer_colors) {  // if same
            array[i] = RIGHT;
            // cout << "R" << endl;
        }
        if (move_colors != answer_colors) {  // if diff OR existing piece but wrong position
            // "MAYBE" algorithm:
            // move:   [m0 m1 m2 m3]
            // answer: [a0 a1 a2 a3]
            // m0 must be equal to a1 a2 or a3 but not a0
            // m1 must be equal to a0 a2 or a3 but not a1
            // m2 must be equal to a0 a1 or a3 but not a2
            // m3 must be equal to a0 a1 or a2 but not a3

            for (int j = 1; j < 4; j++) {
                int k = (i + j) % 4;  // if getPiece(k) incremented to index 4, wrap back to index 0 and continue iteration
                if (move.getPiece(i).getColor() == answer.getPiece(k).getColor()) {  // skip comparisons where "move" index equals "answer" index
                    /*
                    i = 0
                    j = 1, 2, 3 --(i+j)--> 1, 2, 3 --(%4)--> 1, 2, 3
                    move[0] == answer[1, 2, 3]

                    i = 1
                    j = 1, 2, 3 --(i+j)--> 2, 3, 4 --(%4)--> 2, 3, 0
                    move[1] == answer[0, 2, 3]

                    i = 2
                    j = 1, 2, 3 --(i+j)--> 3, 4, 5 --(%4)--> 3, 0, 1
                    move[2] == answer[0, 1, 3]

                    i = 3
                    j = 1, 2, 3 --(i+j)--> 4, 5, 6 --(%4)--> 0, 1, 2
                    move[3] == answer[0, 1, 2]
                    */

                    array[i] = MAYBE;  // if an identical element exists but not in the same index spot, score is MAYBE
                    // cout << "M" << endl;
                    break;
                }
            }
        }
    }
    
    
    /*
    CASE: NEXT 'MAYBE' MUST CHANGE TO 'WRONG' (NOT COMPLETE THOUGH, SEE NEXT CASE)

    move:           GGOP
    answer:         OPGY
    wrong score:    MMMM
    correct score:  M_MM

    move:           GGOP
    answer:         POGB
    wrong score:    MMMM
    correct score:  M_MM

    move:           GGYY
    answer:         YBGB
    wrong score:    MMMM
    correct score:  M_M_



    CASE: IF ALREADY TAKEN BY 'RIGHT', 'MAYBE' MUST CHANGE TO 'WRONG'
    
    move:           GGGY
    answer:         YGGB
    wrong score:    MRRM
    correct score:  _RRM
    */


    // // last check to set an index MAYBE to WRONG if the element was already taken by all RIGHT indicies
    // for (int i = 0; i < REQUIREDLENGTH; i++) {  // iterate through "score" array
    //     if (array[i] == MAYBE) {  // checking the MAYBE case...
    //         for (int j = 0; j < REQUIREDLENGTH; j++) {  // re-iterate 4 times in "move" array (completely separate from the first for loop)
    //             if (move.getPiece(j).getColor() == answer.getPiece(j).getColor()
    //                 && ) {  // only looking at the RIGHT indicies of "move" array

    //             }
    //         }
    //     }
    // }
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
    int j = 0;
    for (int i = 0; i < REQUIREDLENGTH; i++) {
        if (array[i] == RIGHT) {
            j++;
        }
    }
    if (j == 4) {
        return true;
    }
    else {
        return false;
    }
}

}

