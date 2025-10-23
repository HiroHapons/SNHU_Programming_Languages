

#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <string>
#include <vector>

using namespace std;

class ItemTracker {
private:
    // Vectors to store item names and their frequencies
    vector<string> itemNames;
    vector<int> itemCounts;

    // Private helper method to load data from input file
    void LoadDataFromFile(const string& filename);

    // Private helper method to create backup file
    void CreateBackupFile(const string& filename);

    // Private helper method to find index of an item
    int FindItemIndex(const string& itemName);

public:
    // Constructor - loads data from file and creates backup
    ItemTracker(const string& inputFile);

    // Method to search for specific item frequency
    int GetItemFrequency(const string& itemName);

    // Method to print all items with numeric frequencies
    void PrintAllFrequencies();

    // Method to print histogram with asterisks
    void PrintHistogram();
};

#endif // ITEM_TRACKER_H