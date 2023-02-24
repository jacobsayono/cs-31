#ifndef MEALPLAN_H
#define MEALPLAN_H
#include "Enums.h"

class MealPlan {
    private:
        plan mPlan;

    public:
        MealPlan();
        void pickPlan(plan p);
        plan getPlan();
        double cost();
        int mealsEachWeek();
        bool unusedMealsCarryOver();
};

#endif