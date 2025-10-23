/*
 * Main.cpp
 * Airgead Banking Investment Calculator - Main program file
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "Investment.h"

using namespace std;

void displayWelcomeBanner();
void getUserInput(Investment& investment);
void displayInputScreen(const Investment& investment);
void displayReports(const Investment& investment);
void displayTableHeader();
void displaySeparator(int length);
void waitForUser();
void clearScreen();
bool askToContinue();

int main() {
    bool continueProgram = true;

    displayWelcomeBanner();
    cout << "\nPress Enter to continue...";
    cin.get();

    while (continueProgram) {
        clearScreen();
        Investment userInvestment;

        getUserInput(userInvestment);

        cout << "Press Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        clearScreen();
        displayInputScreen(userInvestment);

        cout << "\nPress Enter to see reports...";
        cin.get();

        clearScreen();
        displayReports(userInvestment);

        continueProgram = askToContinue();
    }

    cout << "\nThank you for using Airgead Banking Investment Calculator!" << endl;
    cout << "Goodbye!\n" << endl;

    return 0;
}

void displayWelcomeBanner() {
    cout << string(60, '*') << endl;
    cout << "**                                                        **" << endl;
    cout << "**          AIRGEAD BANKING INVESTMENT CALCULATOR         **" << endl;
    cout << "**                                                        **" << endl;
    cout << "**      See How Your Investment Grows Over Time!          **" << endl;
    cout << "**                                                        **" << endl;
    cout << string(60, '*') << endl;
}

void getUserInput(Investment& investment) {
    double initialAmount, monthlyAmount, interestRate;
    int years;

    cout << string(60, '*') << endl;
    cout << "************ Data Input ************" << endl;

    while (true) {
        cout << "Initial Investment Amount: $";
        if (cin >> initialAmount && initialAmount > 0) {
            investment.setInitialInvestment(initialAmount);
            break;
        }
        else {
            cout << "Invalid input. Please enter a positive number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    while (true) {
        cout << "Monthly Deposit: $";
        if (cin >> monthlyAmount && monthlyAmount >= 0) {
            investment.setMonthlyDeposit(monthlyAmount);
            break;
        }
        else {
            cout << "Invalid input. Please enter a positive number or zero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    while (true) {
        cout << "Annual Interest: %";
        if (cin >> interestRate && interestRate > 0) {
            investment.setAnnualInterest(interestRate);
            break;
        }
        else {
            cout << "Invalid input. Please enter a positive number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    while (true) {
        cout << "Number of years: ";
        if (cin >> years && years > 0) {
            investment.setNumberOfYears(years);
            break;
        }
        else {
            cout << "Invalid input. Please enter a positive integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << string(60, '*') << endl;
}

void displayInputScreen(const Investment& investment) {
    cout << string(60, '*') << endl;
    cout << "************ Data Input ************" << endl;
    cout << fixed << setprecision(2);
    cout << "Initial Investment Amount: $" << investment.getInitialInvestment() << endl;
    cout << "Monthly Deposit: $" << investment.getMonthlyDeposit() << endl;
    cout << "Annual Interest: " << investment.getAnnualInterest() << "%" << endl;
    cout << "Number of years: " << investment.getNumberOfYears() << endl;
    cout << string(60, '*') << endl;
}

void displayReports(const Investment& investment) {
    vector<double> balances;
    vector<double> interest;

    cout << fixed << setprecision(2);

    cout << "\n     Balance and Interest Without Additional Monthly Deposits" << endl;
    displaySeparator(65);
    cout << setw(8) << "Year"
        << setw(28) << "Year End Balance"
        << setw(29) << "Year End Earned Interest" << endl;
    displaySeparator(65);

    investment.calculateBalanceWithoutDeposits(balances, interest);
    for (size_t i = 0; i < balances.size(); ++i) {
        cout << setw(8) << (i + 1)
            << setw(20) << "$" << setw(7) << balances[i]
            << setw(21) << "$" << setw(7) << interest[i] << endl;
    }

    cout << "\n\n     Balance and Interest With Additional Monthly Deposits" << endl;
    displaySeparator(65);
    cout << setw(8) << "Year"
        << setw(28) << "Year End Balance"
        << setw(29) << "Year End Earned Interest" << endl;
    displaySeparator(65);

    investment.calculateBalanceWithDeposits(balances, interest);
    for (size_t i = 0; i < balances.size(); ++i) {
        cout << setw(8) << (i + 1)
            << setw(20) << "$" << setw(7) << balances[i]
            << setw(21) << "$" << setw(7) << interest[i] << endl;
    }

    cout << endl;
}

void displaySeparator(int length) {
    cout << string(length, '=') << endl;
}

void waitForUser() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

bool askToContinue() {
    char response;

    cout << "\n" << string(60, '-') << endl;
    cout << "Would you like to try different investment values? (y/n): ";

    while (true) {
        cin >> response;
        response = tolower(response);

        if (response == 'y') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return true;
        }
        else if (response == 'n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
        else {
            cout << "Invalid input. Please enter 'y' for yes or 'n' for no: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}