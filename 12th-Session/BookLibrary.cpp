#include <iostream>
#include <string>

using namespace std;

string books[100];

void emptyList() {
	for (int i = 0; i < 100; i++) {
		books[i] = "Blank";
	}
}

void addBook(string name) {
	for (int i = 0; i < 100; i++) {
		if (books[i] == "Blank") {
			cout << "OK." << endl;
			books[i] = name;
			return;
		}
	}
}

void removeBook(string name) {
	for (int i = 0; i < 100; i++) {
		if (books[i] == name) {
			cout << "OK." << endl;
			books[i] = "Blank";
			return;
		}
	}
	cout << "Book " << name << " doesn't exist. " << endl;
}

void findBook(string name) {
	for (int i = 0; i < 100; i++) {
		if (books[i] == name) {
			cout << "Book " << name << " at index '" << i << "'" << endl;
			return;
		}
	}
	cout << "Book " << name << " doesn't exit. " << endl;
}

void showBooks() {
	int count = 1;
	for (int i = 0; i < 100; i++) {
		if (books[i] == "Blank") {
			continue;
		}
		else {
			cout << count << ". " << books[i];
			cout << endl;
			count++;
		}
	}
}

void readInput() {
	while (true) {
		string cmd;
		string name;

		cin >> cmd;
		if (cmd == "addBook") {
			cin >> name;
			addBook(name);
		}
		if (cmd == "removeBook") {
			cin >> name;
			removeBook(name);
		}
		if (cmd == "findBook") {
			cin >> name;
			findBook(name);
		}
		if (cmd == "showBooks") {
			showBooks();
		}
	}
}
int main() {
	emptyList();
	readInput();
}
