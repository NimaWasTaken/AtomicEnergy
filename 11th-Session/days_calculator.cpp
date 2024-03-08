/*
Days Calculator: Days Between Two Dates
Calculates many days there are between two dates.
*/
#include <iostream>

using namespace std;

bool isLeap(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int calcDays(int year_A, int month_A, int day_A, int year_B, int month_B, int day_B) {
	int days = 0;
	int currentYear = year_A;

	int month_1 = 31;
	int month_2 = 28;
	if (isLeap(year_A)) {
		month_2 = 29;
	}
	int month_3 = 31;
	int month_4 = 30;
	int month_5 = 31;
	int month_6 = 30;
	int month_7 = 31;
	int month_8 = 31;
	int month_9 = 30;
	int month_10 = 31;
	int month_11 = 30;
	int month_12 = 31;

	while (year_A != year_B || month_A != month_B || day_A != day_B) {

		if (year_A != year_B) {

			if (month_A == 1) {
				days += month_1 - day_A;
				month_A++;
				day_A = 0;
			}
			if (month_A == 2) {
				days += month_2 - day_A;
				month_A++;
				day_A = 0;
			}
			if (month_A == 3) {
				days += month_3 - day_A;
				month_A++;
				day_A == 0;

			}
			if (month_A == 4) {
				days += month_4 - day_A;
				month_A++;
				day_A = 0;

			}
			if (month_A == 5) {
				days += month_5 - day_A;
				month_A++;
				day_A = 0;

			}
			if (month_A == 6) {
				days += month_6 - day_A;
				month_A++;
				day_A = 0;

			}
			if (month_A == 7) {
				days += month_7 - day_A;
				month_A++;
				day_A = 0;

			}
			if (month_A == 8) {
				days += month_8 - day_A;
				month_A++;
				day_A = 0;

			}
			if (month_A == 9) {
				days += month_9 - day_A;
				month_A++;
				day_A = 0;

			}
			if (month_A == 10) {
				days += month_10 - day_A;
				month_A++;
				day_A = 0;

			}
			if (month_A == 11) {
				days += month_11 - day_A;
				month_A++;
				day_A = 0;

			}
			if (month_A == 12) {
				days += month_12 - day_A;
				month_A = 1;
				day_A = 0;
			}
		}
		day_A = 0;

		for (int i = year_B - year_A - 1; i > 0; i--) {
			currentYear++;
			if (isLeap(currentYear)) {
				days += 366;
			}
			else {
				days += 365;
			}
		}

		if (isLeap(year_B)) {
			month_2 = 29;
		}
		else {
			month_2 = 28;
		}

		if (month_B == 1) {
			days += day_B;
			day_A += day_B;
			year_A = year_B;
		}
		if (month_B == 2) {
			days += month_1 + day_B;
			year_A = year_B;
			month_A = month_B;
			day_A += day_B;
		}
		if (month_B == 3) {
			days += month_1 + month_2 + day_B;
			year_A = year_B;
			month_A = month_B;
			day_A += day_B;
		}
		if (month_B == 4) {
			days += month_1 + month_2 + month_3 + day_B;
			year_A = year_B;
			month_A = month_B;
			day_A += day_B;
		}
		if (month_B == 5) {
			days += month_1 + month_2 + month_3 + month_4 + day_B;
			year_A = year_B;
			month_A = month_B;
			day_A += day_B;
		}
		if (month_B == 6) {
			days += month_1 + month_2 + month_3 + month_4 + month_5 + day_B;
			year_A = year_B;
			month_A = month_B;
			day_A += day_B;
		}
		if (month_B == 7) {
			days += month_1 + month_2 + month_3 + month_4 + month_5 + month_6 + day_B;
			year_A = year_B;
			month_A = month_B;
			day_A += day_B;
		}
		if (month_B == 8) {
			days += month_1 + month_2 + month_3 + month_4 + month_5 + month_6 + month_7 + day_B;
			year_A = year_B;
			month_A = month_B;
			day_A += day_B;
		}
		if (month_B == 9) {
			days += month_1 + month_2 + month_3 + month_4 + month_5 + month_6 + month_7 + month_8 + day_B;
			year_A = year_B;
			month_A = month_B;
			day_A += day_B;
		}
		if (month_B == 10) {
			days += month_1 + month_2 + month_3 + month_4 + month_5 + month_6 + month_7 + month_8 + month_9 + day_B;
			year_A = year_B;
			month_A = month_B;
			day_A += day_B;
		}
		if (month_B == 11) {
			days += month_1 + month_2 + month_3 + month_4 + month_5 + month_6 + month_7 + month_8 + month_9 + month_10 + day_B;
			year_A = year_B;
			month_A = month_B;
			day_A += day_B;
		}
		if (month_B == 12) {
			days += month_1 + month_2 + month_3 + month_4 + month_5 + month_6 + month_7 + month_8 + month_9 + month_10 + month_11 + day_B;
			year_A = year_B;
			month_A = month_B;
			day_A += day_B;
		}
	}
	return days - 1;
}

int main() {
	int year_1, month_1, day_1, year_2, month_2, day_2;
	int days;

	cout << "Enter the start date (YY/MM/DD): ";
	cin >> year_1 >> month_1 >> day_1;

	cout << "Enter the end date (YY/MM/DD): ";
	cin >> year_2 >> month_2 >> day_2;

	days = calcDays(year_1, month_1, day_1, year_2, month_2, day_2);
	cout << "There are " << days << " days between " << year_1 << "/" << month_1 << "/" << day_1 << " and " << year_2 << "/" << month_2 << "/" << day_2;
}
