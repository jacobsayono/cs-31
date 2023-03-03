#include "BruinCard.h"

BruinCard::BruinCard() {

}
        
void BruinCard::purchaseMealPlan(MealPlan plan) {
    mPlan = plan;
}

bool BruinCard::hasPurchasedMealPlan() {
    bool ret_value = false;
    if (mPlan == PREMIER19 || REGULAR19 || PREMIER14 || REGULAR14 || PREMIER11 || REGULAR11) {
        ret_value = true;
    }
    return ret_value;
}

plan BruinCard::getPlan() {

}

bool BruinCard::eat(meal m) {
    bool eat;
    
    return eat;
}

void BruinCard::startQuarter() {

}

void BruinCard::newWeek() {

}

void BruinCard::newDay() {

}

int BruinCard::mealsLeftThisWeek() {
    
}