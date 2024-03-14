#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(vector<int> accounts, int id) {
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i] == id) {
			return true;
		}
	}
	return false;
}

vector<int> deposit(vector<int> accounts, vector<int> balances, int id, int amount) {
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i] == id) {
			balances[i] += amount;
			cout << "OK. ";
			return balances;
		}
	}
}

vector<int> withdraw(vector<int> accounts, vector<int> balances, int id, int amount) {
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i] == id) {
			if (amount > balances[i]) {
				cout << "Not enough money. ";
				return balances;
			}
			else {
				balances[i] -= amount;
				cout << "OK. ";
				return balances;
			}
		}
	}
	cout << "Invalid Account. ";
	return balances;
}

void balance(vector<int> accounts, vector<int> balances, int id) {
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i] == id) {
			cout << "Account balance: " << balances[i];
			return;
		}
	}
	cout << "Invalid Account. ";
}

void init() {
	vector<int> accounts;
	vector<int> balances;
	while (true)
	{
		string cmd;
		int id;
		int amount;

		cin >> cmd;
		if (cmd == "deposit") {
			cin >> id;
			cin >> amount;
			if (check(accounts, id)) {
				balances = deposit(accounts, balances, id, amount);
				cout << endl;
			}
			else {
				accounts.push_back(id);
				balances.push_back(amount);
				cout << "OK. ";
				cout << endl;
			}
		}
		else if (cmd == "withdraw") {
			cin >> id;
			cin >> amount;
			balances = withdraw(accounts, balances, id, amount);
			cout << endl;
		}
		else if (cmd == "balance") {
			cin >> id;
			balance(accounts, balances, id);
			cout << endl;
		}
	}
}

int main() {
	init();
}
