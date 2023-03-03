#include "MealPlan.h"

MealPlan::MealPlan() {}

void MealPlan::pickPlan(plan p) {
    mPlan = p;
}

plan MealPlan::getPlan() {
    return mPlan;
}

double MealPlan::cost() {
    double cost;
    switch (mPlan) {
        case PREMIER19:
            cost = 5898.20;
            break;
        case REGULAR19:
            cost = 5278.20;
            break;
        case PREMIER14:
            cost = 5570.04;
            break;
        case REGULAR14:
            cost = 5107.20;
            break;
        case PREMIER11:
            cost = 5018.28;
            break;
        case REGULAR11:
            cost = 4646.64;
            break;
    }
    return cost;
}

int MealPlan::mealsEachWeek() {
    int meals;
    switch (mPlan) {
        case PREMIER19:
        case REGULAR19:
            meals = 19;
            break;
        case PREMIER14:
        case REGULAR14:
            meals = 14;
            break;
        case PREMIER11:
        case REGULAR11:
            meals = 11;
            break;
    }
    return meals;
}

bool MealPlan::unusedMealsCarryOver() {
    bool carry;
    switch (mPlan) {
        case PREMIER19:
        case PREMIER14:
        case PREMIER11:
            carry = true;
            break;
        case REGULAR19:
        case REGULAR14:
        case REGULAR11:
            carry = false;
            break;
    }
    return carry;
}