#include <iostream>
#include <string>
#include <cassert>
#include "BruinCard.h"
using namespace std;

int main() {
    // sample test code working with BruinCard
    BruinCard noMealPlan;
    // cout << noMealPlan.hasPurchasedMealPlan() << endl;
    assert( noMealPlan.hasPurchasedMealPlan( ) == false );
    // cerr << noMealPlan.mealsLeftThisWeek() << endl;
    assert( noMealPlan.mealsLeftThisWeek() == 0 );  
    assert( noMealPlan.eat( BREAKFAST ) == false );
    
    // sample test code working with MealPlan and BruinCard
    BruinCard c;
    MealPlan m;
    m.pickPlan( PREMIER11 );
    c.purchaseMealPlan( m );
    c.startQuarter();                     // Premier plans get all their meals at the start of each quarter
    assert( c.mealsLeftThisWeek() == 11*11 );
    c.newWeek();  // do nothing
    // cout << c.hasPurchasedMealPlan() << endl;
    // cout << c.mealsLeftThisWeek() << endl;
    // cout << c.mealsLeftThisWeek() << endl;
    assert( c.eat( BREAKFAST ) );                 // using one meal on the plan
    // cout << c.mealsLeftThisWeek() << endl;    
    assert( c.eat( BREAKFAST ) );                 // Premier plans can use multiple meals at the same sitting
    // cout << c.mealsLeftThisWeek() << endl;    
    assert( c.mealsLeftThisWeek() == 11*11 - 2 );
    c.newDay();
    assert( c.mealsLeftThisWeek() == 11*11 - 2 );
    c.newWeek();  // do nothing
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
    // cout << d.mealsLeftThisWeek() << endl;
    assert( d.mealsLeftThisWeek() == 10 );
    d.newDay();
    assert( d.eat( BREAKFAST ) );
    assert( d.mealsLeftThisWeek() == 9 );
    d.newWeek();
    assert( d.mealsLeftThisWeek() == 11 );  // Regular plans lose any meals leftover at the start of the new week
    assert( std::to_string( n.cost() ) == "4646.640000" );

    BruinCard e;
    // cout << e.hasPurchasedMealPlan() << endl;
    e.startQuarter();
    e.newWeek();
    // cout << e.hasPurchasedMealPlan() << endl;
    // without a meal plan, BruinCards cannot be used for meals
    assert( e.eat( BREAKFAST ) == false );
    assert( e.mealsLeftThisWeek() == 0 );
    e.newDay();
    assert( e.eat( LUNCH ) == false );
    assert( e.eat( DINNER ) == false );
    assert( e.eat( WEEKENDBRUNCH ) == false );

    BruinCard f;
    MealPlan o;
    o.pickPlan(REGULAR19);
    f.purchaseMealPlan(o);
    f.startQuarter();
    f.newWeek();
    f.newDay();
    // cout << f.mealsLeftThisWeek() << endl;
    f.eat(BREAKFAST);
    // cout << f.mealsLeftThisWeek() << endl;
    f.eat(LUNCH);
    // cout << f.mealsLeftThisWeek() << endl;
    f.eat(DINNER);
    // cout << f.mealsLeftThisWeek() << endl;
    assert(std::to_string(o.cost()) == "5278.200000");
    assert(f.mealsLeftThisWeek() == 16);
    f.newWeek();
    f.newDay();
    assert(f.mealsLeftThisWeek() == 19);

    BruinCard g;
    MealPlan p;
    p.pickPlan( REGULAR14 );
    g.purchaseMealPlan( p );
    g.startQuarter();
    g.newWeek();
    g.newDay();
    g.eat( BREAKFAST );
    g.eat( LUNCH );
    g.eat( DINNER );
    assert(std::to_string( p.cost() ) == "5107.200000" );
    assert(g.mealsLeftThisWeek() == 11);
    g.newWeek();
    g.newDay();
    assert(g.mealsLeftThisWeek() == 14);

    BruinCard h;
    MealPlan q;
    q.pickPlan( REGULAR11 );
    h.purchaseMealPlan( q );
    h.startQuarter();
    h.newWeek();
    h.newDay();
    h.eat( BREAKFAST );
    h.eat( LUNCH );
    h.eat( DINNER );
    assert(std::to_string( q.cost() ) == "4646.640000" );
    assert(h.mealsLeftThisWeek() == 8);
    h.newWeek();
    h.newDay();
    assert(h.mealsLeftThisWeek() == 11);

    cout << "all tests passed!" << endl;


    return 0;
}