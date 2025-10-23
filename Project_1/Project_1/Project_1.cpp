#include <iostream>
using namespace std;

void CheckAppendZero(int Time) {
	if (Time < 10) {
		cout << "0" << Time;
	}
	else {
		cout << Time;
	}
}

void DisplayClock(int Hour, int Min, int Sec, string States) {
	cout << endl;
	int newHour;
	cout << "**************************     **************************" << endl;
	cout << "*      12-Hour-Clock     *     *      24-Hour-Clock     *" << endl;
	cout << "*       ";
	CheckAppendZero(Hour);
	cout << ":";
	CheckAppendZero(Min);
	cout << ":";
	CheckAppendZero(Sec);
	cout << " " << States;
	cout << "       *     *        ";

	
	if (States == "AM") {
		if (Hour == 12) {
			newHour = 0; 
		}
		else {
			newHour = Hour;
		}
	}
	else { 
		if (Hour == 12) {
			newHour = 12;  
		}
		else {
			newHour = Hour + 12;
		}
	}

	CheckAppendZero(newHour);
	cout << ":";
	CheckAppendZero(Min);
	cout << ":";
	CheckAppendZero(Sec);
	cout << "        *" << endl;
	cout << "**************************     **************************" << endl;
}

void DisplayMenu() {
	cout << endl;
	cout << "**************************" << endl;
	cout << "* 1-Add One Hour         *" << endl;
	cout << "* 2-Add One Minute       *" << endl;
	cout << "* 3-Add One Second       *" << endl;
	cout << "* 4-Exit Program         *" << endl;
	cout << "**************************" << endl;
}


void incrementHour(int& hour, string& state) {
	if (hour == 12 && state == "AM") {
		hour = 1;
		state = "PM";
	}
	else if (hour == 12 && state == "PM") {
		hour = 1;
		state = "AM";
	}
	else {
		hour++;
	}
}

int main() {
	int initHour;
	int initMin;
	int initSec;
	int MenuInput = 0;
	string State;

	cout << "Enter initial hours (1-12): ";
	cin >> initHour;
	cin.clear();
	cin.ignore(1000, '\n');
	while (initHour < 1 || initHour > 12) {
		cout << "Invalid hour. Please enter again: ";
		cin >> initHour;
		cin.clear();
		cin.ignore(1000, '\n');
	}

	cout << "Enter initial minutes (0-59): ";  
	cin >> initMin;
	cin.clear();
	cin.ignore(1000, '\n');
	while (initMin < 0 || initMin > 59) {
		cout << "Invalid minutes. Please enter again: ";
		cin >> initMin;
		cin.clear();
		cin.ignore(1000, '\n');
	}

	cout << "Enter initial seconds (0-59): ";  
	cin >> initSec;
	cin.clear();
	cin.ignore(1000, '\n');
	while (initSec < 0 || initSec > 59) {
		cout << "Invalid seconds. Please enter again: ";
		cin >> initSec;
		cin.clear();
		cin.ignore(1000, '\n');
	}

	cout << "Input AM or PM: ";
	cin >> State;
	for (int i = 0; i < State.length(); i++) {
		State[i] = toupper(State[i]);
	}
	while (State != "AM" && State != "PM") {
		cout << "Invalid Input. Please enter again: ";
		cin >> State;
		for (int i = 0; i < State.length(); i++) {
			State[i] = toupper(State[i]);
		}
	}

	DisplayClock(initHour, initMin, initSec, State);

	while (MenuInput != 4) {
		DisplayMenu();
		cout << "Enter Input: ";
		cin >> MenuInput;
		while (MenuInput < 1 || MenuInput > 4) {  
			cout << "Invalid Input. Please enter again: ";
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> MenuInput;
		}

		switch (MenuInput) {
		case 1:
			incrementHour(initHour, State);
			DisplayClock(initHour, initMin, initSec, State);
			break;

		case 2:
			initMin++;
			if (initMin > 59) {
				initMin = 0;
				incrementHour(initHour, State);
			}
			DisplayClock(initHour, initMin, initSec, State);
			break;

		case 3:
			initSec++;
			if (initSec > 59) {
				initSec = 0;
				initMin++;
				if (initMin > 59) {
					initMin = 0;
					incrementHour(initHour, State);
				}
			}
			DisplayClock(initHour, initMin, initSec, State);
			break;

		case 4:
			cout << "Exiting Program....";
			break;
		}
	}

	return 0;
}