#include <string>
#include "clock.h"
using namespace std;

Clock::Clock(int desiredHour, int desiredMinute, int desiredSecond, string ampmValue) {
    hour = desiredHour;
    minute = desiredMinute;
    second = desiredSecond;
    isAM = (ampmValue == "AM");
}

string Clock::displayStandard() {
    // "5:01 PM"
    string answer;
    answer = to_string(hour) + ":";

    if (minute < 10) {
        answer = answer + "0" + to_string(minute);
    }
    else {
        answer = answer + to_string(minute);
    }

    if (isAM) {
        answer = answer + " AM";
    }
    else {
        answer = answer + " PM";
    }

    return answer;
}

string Clock::displayMilitary() {
    // "5:01 PM"
    string hours, minutes, answer;
    minutes = to_string(minute);

    if (!isAM) {
        hours = to_string(hour + 12);
    }
    else {
        if (hour < 10) {
            hours = "0" + to_string(hour);
        }
        else {
            hours = to_string(hour);
        }
    }

    if (minute < 10) {
        minutes = "0" + to_string(minute);
    }
    else {
        minutes = to_string(minute);
    }

    answer = hours + ":" + minutes;
    return answer;
}