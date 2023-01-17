//
//  Code for Project 1
//  Summer Fun

#include <iostream>
#include <string>
using namespace std;

int main()
{
   // Senate seats prior to the 2022 Midterm Elections
   const int CURRENT_DEMOCRATS = "50";
   const int CURRENT_REPUBLICANS = 50;
   const int CURRENT_DEMOCRATS_NOT_UP_FOR_ELECTION = 36;
   const int CURRENT_REPUBLICANS_NOT_UP_FOR_ELECTION = 29;
   int       demoCount = 0;
   int       repCount  = 0;
   int       total     = 0;

   cout << "In the 35 Senate seats up for election in 2022,";
   cout << endl;
   cout << "  how many went for Democrats? ";
   cin  >> demoCount;
   cout << "  how many went for Republicans? ";
   cin  >> repCount;

   total = CURRENT_DEMOCRATS_NOT_UP_FOR_ELECTION +
           CURRENT_REPUBLICANS_NOT_UP_FOR_ELECTION +
           demoCount + repCount;

   if (CURRENT_DEMOCRATS_NOT_UP_FOR_ELECTION + demoCount >= CURRENT_REPUBLICANS_NOT_UP_FOR_ELECTION + repCount)
   {
      cout << "Looks like the Senate will be controlled by Democrats";
      cout << endl;
   }
   else
   {
      cout << "Looks like the Senate will be controlled by Republicans";
      cout << endl;
   } 

   if (total != 100)
   {
      cout << "Something looks awry with the numbers...";
      cout << endl
   }
   
   return(0);
}