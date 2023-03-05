#include "BruinCard.h"
#include <iostream>

BruinCard::BruinCard() {}  // all 'BruinCard::' functions will refer to BruinCard private members only
        
void BruinCard::purchaseMealPlan(MealPlan plan) {
    mPlan = plan;
    mBoughtAMealPlan = true;
}

bool BruinCard::hasPurchasedMealPlan() {
    if (mBoughtAMealPlan == true) {
        return true;
    }
    else {
        return false;
    }
}

plan BruinCard::getPlan() {
    // BruinCard::mPlan [ATTRIBUTE of type class-MealPlan] --->
    // MealPlan::getPlan() [METHOD of type enum-plan] --->
    // plan::REGULAR11 [CONST of type integral]
    return mPlan.getPlan();
}

bool BruinCard::eat(meal m) {
    bool retValue = false;
    if (hasPurchasedMealPlan() == false) {
        retValue = false;
    }
    else {
        if (getPlan() == REGULAR11 || getPlan() == REGULAR14 || getPlan() == REGULAR19) {
            if (hasEatenBreakfast == true || hasEatenLunch == true || hasEatenDinner == true || hasEatenBrunch == true) {
                retValue = false;
            }
            else {
                switch (m) { // meal::BREAKFAST [CONST of type integral]
                    case BREAKFAST:
                        hasEatenBreakfast = true;
                        break;
                    case LUNCH:
                        hasEatenLunch = true;
                        break;
                    case DINNER:
                        hasEatenDinner = true;
                        break;
                    case WEEKENDBRUNCH:
                        hasEatenBrunch = true;
                        break;
                    }
                retValue = true;
                howManyMealsLeft -= 1;
            }
        }
        if (getPlan() == PREMIER11 || getPlan() == PREMIER14 || getPlan() == PREMIER19) {
            retValue = true;
            howManyMealsLeft -= 1;
        }
    }
    return retValue;
}

void BruinCard::startQuarter() {
    std::cout << mBoughtAMealPlan << std::endl;
    switch(getPlan()) {  // BruinCard::getPlan() [METHOD of type enum-plan]
        case PREMIER11:
            howManyMealsLeft = 11*11;
            break;
        case PREMIER14:
            howManyMealsLeft = 14*11;
            break;
        case PREMIER19:
            howManyMealsLeft = 19*11;
            break;
        case REGULAR11:
            howManyMealsLeft = 11;
            break;
        case REGULAR14:
            howManyMealsLeft = 14;
            break;
        case REGULAR19:
            howManyMealsLeft = 19;
            break;
    }
}

void BruinCard::newWeek() {
    std::cout << mBoughtAMealPlan << std::endl;
    hasEatenBreakfast = false;
    hasEatenLunch = false;
    hasEatenDinner = false;
    hasEatenBrunch = false;

    switch(getPlan()) {  // BruinCard::getPlan() [METHOD of type enum-plan]
        case REGULAR11:
            howManyMealsLeft = 11;
            break;
        case REGULAR14:
            howManyMealsLeft = 14;
            break;
        case REGULAR19:
            howManyMealsLeft = 19;
            break;
    }
}

void BruinCard::newDay() {
    hasEatenBreakfast = false;
    hasEatenLunch = false;
    hasEatenDinner = false;
    hasEatenBrunch = false;
}

int BruinCard::mealsLeftThisWeek() {
    if (mBoughtAMealPlan == true) {
        return howManyMealsLeft;
    }
    else {
        return 0;
    }
}