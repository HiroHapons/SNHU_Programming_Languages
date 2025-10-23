
#include "ItemTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Constructor: Initializes tracker by loading data and creating backup
ItemTracker::ItemTracker(const string& inputFile) {
    LoadDataFromFile(inputFile);
    CreateBackupFile("frequency.dat");
}

// Private method to load item data from input file
void ItemTracker::LoadDataFromFile(const string& filename) {
    ifstream inputFile(filename);
    string item;

    
    if (!inputFile.is_open()) {
        cout << "Error: Could not open input file " << filename << endl;
        return;
    }

    
    while (inputFile >> item) {
        int index = FindItemIndex(item);

        if (index == -1) {
            
            itemNames.push_back(item);
            itemCounts.push_back(1);
        }
        else {
            
            itemCounts[index]++;
        }
    }

    inputFile.close();
    cout << "Data loaded successfully from " << filename << endl;
}

// Private method to create backup file with frequency data
void ItemTracker::CreateBackupFile(const string& filename) {
    ofstream outputFile(filename);

    
    if (!outputFile.is_open()) {
        cout << "Error: Could not create backup file " << filename << endl;
        return;
    }

    
    for (int i = 0; i < itemNames.size(); i++) {
        outputFile << itemNames[i] << " " << itemCounts[i] << endl;
    }

    outputFile.close();
    cout << "Backup file created: " << filename << endl << endl;
}

// Private helper method to find index of an item in the vectors
int ItemTracker::FindItemIndex(const string& itemName) {
    for (int i = 0; i < itemNames.size(); i++) {
        if (itemNames[i] == itemName) {
            return i;
        }
    }
    return -1; 
}

// Public method to get frequency of a specific item
int ItemTracker::GetItemFrequency(const string& itemName) {
    int index = FindItemIndex(itemName);

    if (index != -1) {
        return itemCounts[index]; 
    }

    return 0; 
}

// Public method to print all items with their numeric frequencies
void ItemTracker::PrintAllFrequencies() {
    cout << "\n=== Item Frequency List ===" << endl;
    cout << string(40, '-') << endl;

    
    for (int i = 0; i < itemNames.size(); i++) {
        cout << setw(15) << left << itemNames[i]
            << " " << itemCounts[i] << endl;
    }

    cout << string(40, '-') << endl << endl;
}

// Public method to print histogram using asterisks
void ItemTracker::PrintHistogram() {
    cout << "\n=== Item Frequency Histogram ===" << endl;
    cout << string(40, '-') << endl;

    
    for (int i = 0; i < itemNames.size(); i++) {
        cout << setw(15) << left << itemNames[i] << " ";

        
        for (int j = 0; j < itemCounts[i]; j++) {
            cout << "*";
        }

        cout << endl;
    }

    cout << string(40, '-') << endl << endl;
}