#include "BruinCard.h"

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
        switch (getPlan()) {
            case REGULAR11:
            case REGULAR14:
            case REGULAR19:
                if (hasEatenBreakfast == true && m == BREAKFAST) {
                    retValue = false;
                }
                else if (hasEatenLunch == true && m == LUNCH) {
                    retValue = false;
                }
                else if (hasEatenDinner == true && m == DINNER) {
                    retValue = false;
                }
                else if (hasEatenBrunch == true && m == WEEKENDBRUNCH) {
                    retValue = false;
                }
                else {
                    switch (m){
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
                break;
            case PREMIER11:
            case PREMIER14:
            case PREMIER19:
                retValue = true;
                howManyMealsLeft -= 1;
                break;
            }
        }
        return retValue;
}

void BruinCard::startQuarter() {
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