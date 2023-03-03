#include <iostream>
#include <string>
#include <cassert>
#include "BruinCard.h"
using namespace std;

int main() {
    // sample test code working with BruinCard
    BruinCard noMealPlan;
    assert( noMealPlan.hasPurchasedMealPlan( ) == false );
    assert( noMealPlan.mealsLeftThisWeek() == 0 );  
    assert( noMealPlan.eat( BREAKFAST ) == false );
    
    // sample test code working with MealPlan and BruinCard
    BruinCard c;
    MealPlan m;
    m.pickPlan( PREMIER11 );
    c.purchaseMealPlan( m );
    c.startQuarter();                     // Premier plans get all their meals at the start of each quarter
    assert( c.mealsLeftThisWeek() == 11*11 );
    c.newWeek();
    assert( c.eat( BREAKFAST ) );                 // using one meal on the plan
    assert( c.eat( BREAKFAST ) );                 // Premier plans can use multiple meals at the same sitting
    assert( c.mealsLeftThisWeek() == 11*11 - 2 );
    c.newDay();
    assert( c.mealsLeftThisWeek() == 11*11 - 2 );
    c.newWeek();
    assert( c.mealsLeftThisWeek() == 11*11 - 2 );
    assert( std::to_string( m.cost() ) == "5018.280000" );

    BruinCard d;
    MealPlan n;
    n.pickPlan( REGULAR11 );
    d.purchaseMealPlan( n );
    d.startQuarter();
    d.newWeek();
    assert( d.mealsLeftThisWeek() == 11 );  // Regular plans get their meals at the start of each week
    assert( d.eat( BREAKFAST ) );
    assert( d.eat( BREAKFAST ) == false );          // Regular plans cannot dine twice at the same meal
    assert( d.mealsLeftThisWeek() == 10 );
    d.newDay();
    assert( d.eat( BREAKFAST ) );
    assert( d.mealsLeftThisWeek() == 9 );
    d.newWeek();
    assert( d.mealsLeftThisWeek() == 11 );  // Regular plans lose any meals leftover at the start of the new week
    assert( std::to_string( n.cost() ) == "4646.640000" );

    BruinCard e;
    e.startQuarter();
    e.newWeek();
    // without a meal plan, BruinCards cannot be used for meals
    assert( e.eat( BREAKFAST ) == false );
    assert( e.mealsLeftThisWeek() == 0 );
    e.newDay();
    assert( e.eat( LUNCH ) == false );
    assert( e.eat( DINNER ) == false );
    assert( e.eat( WEEKENDBRUNCH ) == false );
    cout << "all tests passed!" << endl; 
    return( 0 ); 
}