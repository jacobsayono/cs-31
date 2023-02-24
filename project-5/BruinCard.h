#ifndef BRUINCARD_H
#define BRUINCARD_H
#include "MealPlan.h"

class BruinCard {
    private:
        MealPlan mPlan;
        bool mBoughAMealPlan;

        bool hasEathenBreakfast;
        bool hasEatenLunch;
        bool hasEatenDinner;
        bool hasEatenBrunch;

        int howManyMealsLeft;
    
    public:
        BruinCard();
        
        void purchaseMealPlan(MealPlan plan);
        bool hasPurchasedMealPlan();
        plan getPlan();

        bool eat(meal m);

        void startQuarter();
        void newWeek();
        void newDay();
        int mealsLeftThisWeek();
};

#endif /* BRUINCARD_H */