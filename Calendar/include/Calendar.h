#ifndef CALENDAR_H
#define CALENDAR_H


class Calendar
{
private:
    int year;
    int month;

public:
    Calendar(int y, int m);
    void display();
    void nextMonth();
    void previousMonth();

private:
    int getDaysInMonth(int y, int m);

    int getStartDay(int y, int m);

    bool isLeapYear(int y);
};

#endif // CALENDAR_H
