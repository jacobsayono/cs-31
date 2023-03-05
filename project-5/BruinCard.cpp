#include "BruinCard.h"

BruinCard::BruinCard() {}  // all 'BruinCard::' functions will refer to BruinCard private members only
        
void BruinCard::purchaseMealPlan(MealPlan plan) {
    mPlan = plan;  // set BruinCard::mPlan attribute of type MealPlan to the input plan of type MealPlan
    mBoughtAMealPlan = true;  // set BruinCard::mBoughtAMealPlan attribute to true once we purhcased a plan
}

bool BruinCard::hasPurchasedMealPlan() {
    if (mBoughtAMealPlan == true) {  // use the attribute that was set to true (after purchasing a meal plan) to make the function return true
        return true;  // eat() will depent on this function, which has public access, unlike mBoughAMealPlan, which only has private access
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
    if (hasPurchasedMealPlan() == false) {  // first, check that the BruinCard has bought a meal plan, if not, don't allow to eat()
        retValue = false;
    }
    else {
        switch (getPlan()) {  // based on what plan the BruinCard has...
            case REGULAR11:
            case REGULAR14:
            case REGULAR19:
                if (hasEatenBreakfast == true && m == BREAKFAST) {  // this prevents repeatability of the same meal if the BruinCard is on a regular plan
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
                    switch (m) {
                        case BREAKFAST:  // but if it's not the same meal in the same day, you can eat it
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
                        howManyMealsLeft -= 1;  // subtract 1 from total meals left
                }
                break;
            case PREMIER11:  // premier plans are allowed to eat the same meal more than once in a day
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
            howManyMealsLeft = 11*11;  // set the starting meal number for each plan
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
    hasEatenBreakfast = false;  // reset eat() "history"
    hasEatenLunch = false;
    hasEatenDinner = false;
    hasEatenBrunch = false;

    switch(getPlan()) {  // BruinCard::getPlan() [METHOD of type enum-plan]
        case REGULAR11:
            howManyMealsLeft = 11;  // for regular plans, we reset the number of meals to the very start of "the quarter"
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
    hasEatenBreakfast = false;  // reset eat() "history"
    hasEatenLunch = false;
    hasEatenDinner = false;
    hasEatenBrunch = false;
}

int BruinCard::mealsLeftThisWeek() {
    if (mBoughtAMealPlan == true) {  // only allow this function to return the number of meals if the BruinCard has bought a plan
        return howManyMealsLeft;
    }
    else {
        return 0;  // if not, the BruinCard can only hold 0 meals
    }
}