//
//  Enums.h
//

#ifndef EnumsH
#define EnumsH

// the scoring rubric for a Score object
enum ANSWER { RIGHT, WRONG, MAYBE };

// the game outcome held in a Mastermind object
enum GAMEOUTCOME { GAMEWON, GAMELOST, GAMENOTOVER };

// the possible colors held in a Piece object
enum COLOR { RED, BLUE, GREEN, YELLOW, PURPLE, ORANGE, NOTVALID };
const int  VALIDCOLORCOUNT = 6;

#endif 

