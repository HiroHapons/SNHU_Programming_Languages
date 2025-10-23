

#include "ItemTracker.h"
#include <iostream>
#include <string>

using namespace std;

// Function prototype for displaying menu
void DisplayMenu();

int main() {
    
    ItemTracker tracker("CS210_Project_Three_Input_File.txt");

    int menuChoice = 0;
    string searchItem;
    int frequency;

    // Main program loop
    while (menuChoice != 4) {
        DisplayMenu();
        cin >> menuChoice;

        // Input validation for menu choice
        while (cin.fail() || menuChoice < 1 || menuChoice > 4) {
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            cout << "Invalid input. Please enter a number between 1 and 4: ";
            cin >> menuChoice;
        }

        // Process menu selection using switch statement
        switch (menuChoice) {
        case 1:
            
            cout << "\nEnter the item name to search: ";
            cin >> searchItem;

            frequency = tracker.GetItemFrequency(searchItem);

            if (frequency > 0) {
                cout << "\n" << searchItem << " appears "
                    << frequency << " time(s)." << endl << endl;
            }
            else {
                cout << "\n" << searchItem
                    << " was not found in the records." << endl << endl;
            }
            break;

        case 2:
            
            tracker.PrintAllFrequencies();
            break;

        case 3:
            
            tracker.PrintHistogram();
            break;

        case 4:
            
            cout << "\nThank you for using the Corner Grocer Item Tracker!" << endl;
            cout << "Exiting program..." << endl;
            break;

        default:
            
            cout << "Unexpected error occurred." << endl;
            break;
        }
    }

    return 0;
}

// Function to display the main menu
void DisplayMenu() {
    cout << "========================================" << endl;
    cout << "  Corner Grocer Item Tracking System  " << endl;
    cout << "========================================" << endl;
    cout << "1. Search for item frequency" << endl;
    cout << "2. Display all item frequencies" << endl;
    cout << "3. Display histogram" << endl;
    cout << "4. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Enter your choice (1-4): ";
}