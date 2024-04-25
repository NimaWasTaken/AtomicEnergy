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
    vector<int> daysInMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    bool isLeap() {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    bool isValid() {
        if (year < 0 || day < 0 || month < 0 || month > 12) {
            return false;
        }
        if (isLeap()) {
            daysInMonth[1] = 29;
        }
        return day <= daysInMonth[month - 1];
    }

    void increaseOneDay() {
        day++;
        if (!isValid()) {
            day = 1;
            month++;
            if (!isValid()) {
                month = 1;
                year++;
            }
        }
    }
public:
    Date(int year, int month, int day) {

        this->year = year;
        this->month = month;
        this->day = day;

        if (!isValid()) {
            cout << "Invalid Format. ";
            exit(1);
        }
    }

    void printDate() {
        cout << year << "/" << month << "/" << day;
    }

    void increaseDays(int days) {
        for (int i = 0; i < days; i++) {
            increaseOneDay();
        }
    }

    bool isEqual(Date date) {
        return (day == date.day) && (month = date.month) && (year = date.year);
    }
};

class Human {
private:
    string name;
    Date birthdate;
public:
    Human(string name, int year, int month, int day)
        :birthdate(year, month, day)
    {
        this->name = name;
    }

    void printInfo() {
        cout << "Name: " << name << "\n";
        cout << "Birthdate: "; birthdate.printDate();

    }
};

int main() {
    int year1, month1, day1;
    int year2, month2, day2;

    cout << "Enter the first date: ";
    cin >> year1 >> month1 >> day1;
    cout << "Enter the second date: ";
    cin >> year2 >> month2 >> day2;

    Date date1(year1, month1, day1);
    Date date2(year2, month2, day2);

    Human human_1("Nima", 2000, 1, 1);
    human_1.printInfo();
}
