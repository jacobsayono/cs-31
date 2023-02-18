#include <iostream>
#include <string>
#include "clock.h"

Clock::Clock(int desiredHour, int desiredMinute, int desiredSecond, std::string ampmValue) {
    hour = desiredHour;
    minute = desiredMinute;
    second = desiredSecond;
    isAM = (ampmValue == "AM");
}

std::string Clock::displayStandard() {
    // "5:01 PM"
    std::string answer;
    answer = std::to_string(hour) + ":";

    if (minute < 10) {
        answer = answer + "0" + std::to_string(minute);
    }
    else {
        answer = answer + std::to_string(minute);
    }

    if (isAM) {
        answer = answer + " AM";
    }
    else {
        answer = answer + " PM";
    }

    return answer;
}

std::string Clock::displayMilitary() {
    // "17:01 PM"
    std::string hours, minutes, answer;
    minutes = std::to_string(minute);

    if (!isAM) {
        hours = std::to_string(hour + 12);
    }
    else {
        if (hour < 10) {
            hours = "0" + std::to_string(hour);
        }
        else {
            hours = std::to_string(hour);
        }
    }

    if (minute < 10) {
        minutes = "0" + std::to_string(minute);
    }
    else {
        minutes = std::to_string(minute);
    }

    answer = hours + ":" + minutes;
    return answer;
}