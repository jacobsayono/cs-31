#include "BruinCard.h"
#include <iostream>

BruinCard::BruinCard() {}  // all 'BruinCard::' functions will refer to BruinCard private members only
        
void BruinCard::purchaseMealPlan(MealPlan plan) {
    mPlan = plan;
}

bool BruinCard::hasPurchasedMealPlan() {
    // mBoughtAMealPlan = false;  // BruinCard::mBoughtAMealPlan [ATTRIBUTE of type bool]
    switch(getPlan()) {  // BruinCard::getPlan() [METHOD of type enum-plan]
        case REGULAR11:
        case PREMIER11:
        case REGULAR14:
        case PREMIER14:
        case REGULAR19:
        case PREMIER19:
            mBoughtAMealPlan = true;
            break;
    }
    return mBoughtAMealPlan;
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
            std::cout << "bye11p" << std::endl;
            howManyMealsLeft = 11*11;
            break;
        case PREMIER14:
            std::cout << "bye14p" << std::endl;
            howManyMealsLeft = 14*11;
            break;
        case PREMIER19:
            std::cout << "bye19p" << std::endl;
            howManyMealsLeft = 19*11;
            break;
        case REGULAR11:
            std::cout << "bye11r" << std::endl;
            howManyMealsLeft = 11;
            break;
        case REGULAR14:
            std::cout << "bye14r" << std::endl;
            howManyMealsLeft = 14;
            break;
        case REGULAR19:
            std::cout << "bye19r" << std::endl;
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
            std::cout << "hi11r" << std::endl;
            howManyMealsLeft = 11;
            break;
        case REGULAR14:
            std::cout << "hi14r" << std::endl;
            howManyMealsLeft = 14;
            break;
        case REGULAR19:
            std::cout << "hi19r" << std::endl;
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
    return howManyMealsLeft;
}