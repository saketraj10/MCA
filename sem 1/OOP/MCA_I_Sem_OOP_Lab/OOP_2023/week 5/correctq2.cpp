#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    Date& operator++() {
        day++;

        if (month == 2) {
            if (isLeapYear(year) ? (day > 29) : (day > 28)) {
                day = 1;
                month++;
            }
        }
        else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
            day = 1;
            month++;
        }
        else if (day > 31) {
            day = 1;
            month++;
        }

        if (month > 12) {
            month = 1;
            year++;
        }

        return *this;
    }

    void display() const {
        std::cout << day << "/" << month << "/" << year << std::endl;
    }
};

bool isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }

    if (month == 2) {
        if (year % 4 == 0) {
            if (day > 29) {
                return false;
            }
        } else {
            if (day > 28) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int day, month, year;

    do {
        std::cout << "Enter a positive date (day month year): ";
        if (!(std::cin >> day >> month >> year) || !isValidDate(day, month, year)) {
            std::cerr << "Invalid input. Please enter a valid date." << std::endl;
            std::cin.clear();
            while (std::cin.get() != '\n');  // Clear the input buffer
        }
    } while (!isValidDate(day, month, year));

    Date date(day, month, year);

    ++date;

    std::cout << "Date after incrementing by one day: ";
    date.display();

    return 0;
}
