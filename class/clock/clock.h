#ifndef CLOCK_H
#define CLOCK_H

class Clock {
    private:
        int hour;
        int minute;
        int second;
        bool isAM;
    public:
        Clock(int desiredHour, int desiredMinute, int desiredSecond, string ampmValue);
        string displayStandard();
        string displayMilitary();
};

#endif /* CLOCK_H */