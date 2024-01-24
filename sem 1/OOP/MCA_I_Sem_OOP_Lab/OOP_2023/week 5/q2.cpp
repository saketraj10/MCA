//Program to create a class Date which contains integer members to represent day, month and year overload ++ operator to increment the value of Date object by one.
//Name: Saket Raj
//Reg No: 230970079
//Date: 15-09-2023
#include<iostream>
using namespace std;

class Date
{
        private:
                int day, month, year;
        public:
                Date(int d, int m, int y)
                {
                        day = d;
                        month = m;
                        year = y;
                }

                bool isLeapYear()
                {
                        return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
                }

                void incrementDate()
                {
                        if (month == 12 && day == 31)
                        {
                                day = 1;
                                month = 1;
                                year++;
                        }
                        else if (month == 2)
                        {
                                if (isLeapYear() && day == 29)
                                {
                                        day = 1;
                                        month++;
                                }
                                else if (!isLeapYear() && day == 28)
                                {
                                        day = 1;
                                        month++;
                                }
                                else
                                {
                                        day++;
                                }
                        }
 else if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30)
                        {
                                day = 1;
                                month++;
                        }
                        else if (day == 31)
                        {
                                day = 1;
                                month++;
                        }
                        else
                        {
                                day++;
                        }
                }

                void displayDate()
                {
                        cout << "Date After Incrementing: " << day << "/" << month << "/" << year << endl;
                }
};

int main()
{
        int day, month, year;
        cout << "Enter the Date: " << endl;
        cout << "day: ";
        cin >> day;
        cout << "month: ";
        cin >> month;
        cout << "year: ";
        cin >> year;

        if (day <= 0 || month <= 0 || year < 0 || month > 12 || (day > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month ==
10 || month == 12)) || (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) || (day > 29 && month == 2) || (!Date(day, month, year).isLeapYear() && day > 28))
        {
                cout << "Enter a valid date!" << endl;
                return 1;
        }

        Date d(day, month, year);
        d.incrementDate();
        d.displayDate();

        return 0;
}