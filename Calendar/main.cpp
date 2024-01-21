#include <iostream>
#include <iomanip>
#include <Calendar.h>

int main() {
    int year, month;

    std::cout << "Enter year and month (YYYY MM): ";
    std::cin >> year >> month;

    Calendar calendar(year, month);

    while (true) {
        std::cout << "\n" << std::setw(23) << std::setfill('-') << " Calendar " << std::setw(23) << std::setfill('-') << '\n';
        std::cout << std::setfill(' ');
        std::cout << "Year: " << year << "   Month: " << month << "\n\n";
        calendar.display();

        std::cout << "\n1. Next Month   2. Previous Month   3. Exit\n";
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                calendar.nextMonth();
                break;
            case 2:
                calendar.previousMonth();
                break;
            case 3:
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
