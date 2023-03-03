#include "BruinCard.h"

BruinCard::BruinCard() {  // all 'BruinCard::' functions will refer to BruinCard private members only
    mBoughtAMealPlan = false;
}
        
// set the number of meals left for the quarter based on plan
void BruinCard::purchaseMealPlan(MealPlan plan) {
    switch(getPlan()) {  // BruinCard::getPlan() [METHOD of type enum-plan]
        case REGULAR11:
        case PREMIER11:
            howManyMealsLeft = 11*11;
            break;
        case REGULAR14:
        case PREMIER14:
            howManyMealsLeft = 14*11;
            break;
        case REGULAR19:
        case PREMIER19:
            howManyMealsLeft = 19*11;
            break;
    }
}

bool BruinCard::hasPurchasedMealPlan() {
    mBoughtAMealPlan = false;  // BruinCard::mBoughtAMealPlan [ATTRIBUTE of type bool]
    // if (getPlan() == REGULAR11 || PREMIER11 || REGULAR14 || PREMIER14 || REGULAR19 || PREMIER19) {  // BruinCard::getPlan() [METHOD of type enum-plan]
    //     mBoughtAMealPlan = true;
    // }
    return mBoughtAMealPlan;
}

plan BruinCard::getPlan() {
    // BruinCard::mPlan [ATTRIBUTE of type class-MealPlan] --->
    // MealPlan::getPlan() [METHOD of type enum-plan] --->
    // plan::REGULAR11 [CONST of type integral]
    return mPlan.getPlan();
}

bool BruinCard::eat(meal m) {
    if (hasPurchasedMealPlan() == false) {
        return false;
    }
    else {
        hasEatenBreakfast = false;
        hasEatenLunch = false;
        hasEatenDinner = false;
        hasEatenBrunch = false;
        switch (m) { // meal::BREAKFAST [CONST of type integral]
            BREAKFAST:
                hasEatenBreakfast = true;
                break;
            LUNCH:
                hasEatenLunch = true;
                break;
            DINNER:
                hasEatenDinner = true;
                break;
            WEEKENDBRUNCH:
                hasEatenBrunch = true;
                break;
        }
    }

}

void BruinCard::startQuarter() {

}

void BruinCard::newWeek() {

}

void BruinCard::newDay() {

}

int BruinCard::mealsLeftThisWeek() {
    
}