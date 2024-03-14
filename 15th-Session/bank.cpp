#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct User
{
	int id;
	int balance;
};

bool check(vector<User> information, int id) {
	for (int i = 0; i < information.size(); i++) {
		if (information[i].id == id) {
			return true;
		}
	}
	return false;
}

vector<User> deposit(vector<User> information, int id, int amount) {
	for (int i = 0; i < information.size(); i++) {
		if (information[i].id == id) {
			information[i].balance += amount;
			cout << "OK. ";
			return information;
		}
	}
}

vector<User> withdraw(vector<User> information, int id, int amount) {
	for (int i = 0; i < information.size(); i++) {
		if (information[i].id == id) {
			if (amount > information[i].balance) {
				cout << "Not enough money. ";
				return information;
			}
			else {
				information[i].balance -= amount;
				cout << "OK. ";
				return information;
			}
		}
	}
	cout << "Invalid Account. ";
	return information;
}

void balance(vector<User> information, int id) {
	for (int i = 0; i < information.size(); i++) {
		if (information[i].id == id) {
			cout << "Account balance: " << information[i].balance;
			return;
		}
	}
	cout << "Invalid Account. ";
}

void init() {
	vector<User> information;

	while (true)
	{
		string cmd;
		int id;
		int amount;

		cin >> cmd;
		if (cmd == "deposit") {
			cin >> id;
			cin >> amount;
			if (check(information, id)) {
				information = deposit(information, id, amount);
				cout << endl;
			}
			else {
				information.push_back({id,amount});
				cout << "OK. ";
				cout << endl;
			}
		}
		else if (cmd == "withdraw") {
			cin >> id;
			cin >> amount;
			information = withdraw(information, id, amount);
			cout << endl;
		}
		else if (cmd == "balance") {
			cin >> id;
			balance(information, id);
			cout << endl;
		}
	}
}

int main() {
	init();
}
