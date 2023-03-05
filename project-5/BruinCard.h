#ifndef BRUINCARD_H
#define BRUINCARD_H
#include "MealPlan.h"

class BruinCard {
    private:
        MealPlan mPlan;
        bool mBoughtAMealPlan = false;

        bool hasEatenBreakfast = false;
        bool hasEatenLunch = false;
        bool hasEatenDinner = false;
        bool hasEatenBrunch = false;

        int howManyMealsLeft = 0;
    
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