#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
    vector<int> daysInMonth;

    bool isLeap(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    bool isValid(int year, int month, int day) {
        daysInMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        if (year < 0 || day < 0 || month < 0 || month > 12) {
            return false;
        }

        if (isLeap(year)) {
            daysInMonth[1] = 29;
        }

        return day <= daysInMonth[month - 1];
    }

public:
    void setDate(int year, int month, int day) {
        if (isValid(year, month, day)) {
            this->year = year;
            this->month = month;
            this->day = day;
        }
        else {
            cout << "Invalid Format. ";
            exit(1);
        }
    }

    void printDate() {
        cout << "Date: " << year << "/" << month << "/" << day;
    }
};

int main() {
    Date date;
    int year;
    int month;
    int day;

    cout << "Enter the date (YY/MM/DD): ";
    cin >> year >> month >> day;

    date.setDate(year, month, day);
    date.printDate();

}
