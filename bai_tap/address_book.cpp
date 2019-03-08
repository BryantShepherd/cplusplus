#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Entry{
    string name, number;
    Entry() {
        name = "unknown";
        number = "unknown";
    }
    Entry(string _name, string _number) {
        name = _name;
        number = _number;
    }
    void scanName() {
        fflush(stdin); //cin.ignore()
        cout << "\tName: ";
        getline(cin, name);
    }
    void scanNumber() {
        fflush(stdin);
        cout << "\tNumber: ";
        getline(cin, number);
    }
    void printInfo() {
        cout << name << " " << number << endl;
    }
    string getName() {
        return name;
    }
    string getNumber() {
        return number;
    }
};

void printAllEntries(vector <Entry> &entries);

int main() {
    const char ADD_ENTRY = '1';
    const char REMOVE_ENTRY = '2';
    const char EDIT_ENTRY = '3';
    const char PRINT_ALL_ENTRIES = '4';
    const char CLEAR_ALL_ENTRIES = '5';
    const char QUIT = '6';

    char chooseAction;
    string entryName, entryNumber;
    Entry newEntry;
    vector <Entry> entryList;
    bool notQuit = true;

    cout << "\t1. Add an entry\n";
    cout << "\t2. Remove an entry.\n";
    cout << "\t3. Edit an entry\n";
    cout << "\t4. Print all entríe.\n";
    cout << "\t5. Clear all entries.\n"; 
    cout << "\t6. QUIT\n";
    cout << "\t------------------\n";
    
    while(notQuit) {
        cout << "Choose Action: ";
        cin >> chooseAction;
        switch(chooseAction) {
            default: {
                cin.ignore(256, '\n');
                break;
            }
            case ADD_ENTRY: {
                newEntry.scanName();
                newEntry.scanNumber();
                entryList.push_back(newEntry);
                break;
            }
            case REMOVE_ENTRY: {
                int deleteElem;
                printAllEntries(entryList);

                cout << "Erase element (-1 to back): ";
                cin >> deleteElem;
                if (deleteElem == -1 || deleteElem > entryList.size()) break;
                entryList.erase(entryList.begin() + deleteElem - 1);
                break;
            }
            case PRINT_ALL_ENTRIES: {
                cout << "All entries" << endl;
                printAllEntries(entryList);
                break;
            }
            case EDIT_ENTRY: {
                int editElem;
                printAllEntries(entryList);
                cout << "Erase element (-1 to back): ";
                cin >> editElem;
                if (editElem == -1 || editElem > entryList.size()) break;
                entryList[editElem - 1].scanName();
                entryList[editElem - 1].scanNumber();
                break;
            }
            case QUIT: {
                exit(0);
            }
        }
        cout << endl;
    }
    return 0;
}

void printAllEntries(vector <Entry> &entries) {
    int list_count = 1;
    for (auto i : entries) {
        cout << "\t" << list_count << ". Name: " << i.name << "\t" << "Number: " << i.number << endl; //in thang hang, hoac tao mot khoang trong de in danh ba o dau.
        list_count++;
    }
}