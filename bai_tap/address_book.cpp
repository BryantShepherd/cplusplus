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
    //should I use function, or just cin >> entry.name?
    void scanName() {
        fflush(stdin); //cin.ignore(), sap dung getline nen can xoa cache
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
string stringToLower(string a);
void searchEntry(Entry &entryElem, string &searchQuery);

int main() {
    const char ADD_ENTRY = '1';
    const char REMOVE_ENTRY = '2';
    const char EDIT_ENTRY = '3';
    const char PRINT_ALL_ENTRIES = '4';
    const char CLEAR_ALL_ENTRIES = '5';
    const char SEARCH_ENTRY = '6';
    //NOTE: sort by first name, last name, by phone number
    const char QUIT = '0';

    char chooseAction;
    string entryName, entryNumber;
    Entry newEntry;
    vector <Entry> entryList {{"Alvin Levenson", "(487) 417-0829"}, {"Ben Balake", "(743) 395-1377"}, {"Chris Brown", "(357) 679-3200"}, {"Chris MyAss", "(803) 563-1534"}, {"David Copperfield", "(793) 497-9775"}, {"Emilia Mayweather", "(743) 796-6980"}};
    bool notQuit = true;
    //NOTE: divide into sections of choices. Press More to show more option. 
    cout << "\t1. Add an entry\n";
    cout << "\t2. Remove an entry.\n";
    cout << "\t3. Edit an entry\n";
    cout << "\t4. Print all entríe.\n";
    cout << "\t5. Clear all entries.\n"; 
    cout << "\t0. QUIT\n";
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
                //Get user input
                newEntry.scanName();
                newEntry.scanNumber();
                //Append to contact list
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
                //NOTE: keep the contact in a file.
                cout << "All entries: " << endl;
                printAllEntries(entryList);
                break;
            }
            case EDIT_ENTRY: {
                int editElem;
                printAllEntries(entryList);
                cout << "Edit element (-1 to back): ";
                //NOTE: check if user want to edit one or both info
                cin >> editElem;
                if (editElem == -1 || editElem > entryList.size()) break;

                entryList[editElem - 1].scanName();
                entryList[editElem - 1].scanNumber();
                break;
            }
            case CLEAR_ALL_ENTRIES: {
                entryList.clear();
                //NOTE: confirm before deleting
                cout << "\tContact list deleted.\n";
                break;
            }
            case SEARCH_ENTRY: {
                string searchQuery;
                fflush(stdin);
                getline(cin, searchQuery);

                for (auto i : entryList) {
                    //NOTE: clean the code, count the time search Query appear then print out in the that order. 
                    //NOTE: maybe add search by first name, last name, ...
                    //NOTE: print something if find nothing.
                    searchEntry(i, searchQuery);
                }
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
    if (entries.size() > 0) {
        int list_count = 1;
        //NOTE: line up when print out. OR keep a space at the beginning of the program to show contact.
        for (auto i : entries) {
            cout << "\t" << list_count << ". Name: " << i.name << "\t" << "Number: " << i.number << endl; 
            list_count++;
        }
    }
    else {
        cout << "\tContact list is empty.\n";
    }
    
}

string stringToLower(string a) {
    for (int i = 0; i < a.size(); i++) {
        a[i] = tolower(a[i]);
    }
    return a;
}

void searchEntry(Entry &entryElem, string &searchQuery) {
    string lowerName = stringToLower(entryElem.name);
    string lowerSearchQuery = stringToLower(searchQuery);

    if ((lowerName.find(lowerSearchQuery) != -1) || (entryElem.getNumber().find(searchQuery) != -1)) {
        cout << "\tName: " << entryElem.getName() << "\t" << "Number: " << entryElem.getNumber() << endl;
    }
}