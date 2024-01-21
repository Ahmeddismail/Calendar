#include "Calendar.h"
#include <iostream>
#include <iomanip>

Calendar::Calendar(int y, int m) : year(y), month(m)
{
    //ctor
}

///////////////////////////////////////////////////////////
void Calendar::display() {
        std::cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
        int daysInMonth = getDaysInMonth(year, month);
        int startDay = getStartDay(year, month);

        for (int i = 0; i < startDay; ++i)
            std::cout << "     ";

        for (int day = 1; day <= daysInMonth; ++day) {
            std::cout << std::setw(5) << day;
            if ((startDay + day - 1) % 7 == 0 || day == daysInMonth)
                std::cout << '\n';
        }
    }

///////////////////////////////////////////////////////////
void Calendar::nextMonth() {
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }

///////////////////////////////////////////////////////////
void Calendar::previousMonth() {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
    }

///////////////////////////////////////////////////////////
int Calendar::getDaysInMonth(int y, int m) {
        static const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int days = daysInMonth[m];
        if (m == 2 && isLeapYear(y))
            days++;
        return days;
    }

///////////////////////////////////////////////////////////
int Calendar::getStartDay(int y, int m) {
        // Zeller's Congruence algorithm to find the day of the week
        if (m < 3) {
            m += 12;
            y--;
        }
        int k = y % 100;
        int j = y / 100;
        int day = (1 + 13 * (m + 1) / 5 + k + k / 4 + j / 4 - 2 * j) % 7;
        return (day + 5) % 7; // Convert to Sunday-based indexing (0-indexed)
    }


///////////////////////////////////////////////////////
bool Calendar::isLeapYear(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }
