#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date {
private:
    int year;
    int month;
    int day;

    string date;

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
            month++;
            day = 1;
        }

        if (!isValid()) {
            year++;
            month = 1;
        }

        date = to_string(year) + "/" + to_string(month) + "/" + to_string(day);
    }

public:
    Date(int year, int month, int day) {

        this->year = year;
        this->month = month;
        this->day = day;

        date = to_string(year) + "/" + to_string(month) + "/" + to_string(day);

        if (!isValid()) {
            this->year = 0;
            this->month = 0;
            this->day = 0;
        }
    }

    string returnDate() {
        return date;
    }

    void increaseDays(int days) {
        for (int i = 0; i < days; i++) {
            increaseOneDay();
        }
    }

    bool isEqual(Date date) {
        return (this->date == date.date);
    }

    bool isBirthday(Date date) {
        return (day == date.day) && (month = date.month);
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
        cout << "{ " << "Name: " << name << " | Birthdate: " << birthdate.returnDate() << " }\n";
    }

    string returnName() {
        return name;

    }

    bool isBirthday(Date date) {
        return birthdate.isBirthday(date);
    }
};

class System {
private:
    string name;
    Date date;
    vector<Human> people;
public:
    System(string name, int year, int month, int day)
        :date(year, month, day)
    {
        this->name = name;
    }

    void addPerson(Human human) {
        people.push_back(human);
    }

    string returnDate() {
        return date.returnDate();
    }

    void printInfo() {
        cout << "Name: " << name;
        cout << "\nDate: " << returnDate();
        cout << "\nPeople: ";
        for (int i = 0; i < people.size(); i++) {
            people[i].printInfo();
        }
    }

    void increaseOneDay() {
        date.increaseDays(1);

        for (int i = 0; i < people.size(); i++) {
            if (people[i].isBirthday(date)) {
                cout << "Happy birthday, " << people[i].returnName() << "!\n";
            }
        }
    }
};

int main() {
    Human human_1("Nima", 2002, 4, 29);
    Human human_2("Hashem", 1984, 5, 6);
    Human human_3("Mahmoud", 1998, 5, 14);

    System system("taryak", 2024, 4, 26);
    system.addPerson(human_1);
    system.addPerson(human_2);
    system.addPerson(human_3);
}
