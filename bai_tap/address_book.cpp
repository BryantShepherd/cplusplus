#include <iostream>
#include <string>
#include <vector>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>


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
        cout << "Name: " << name << "\tNumber: " << number << endl;
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
void printSearchResults(Entry &entryElem, string &searchQuery, bool &foundResult);
bool askToConfirm();

int main() {
    const char ADD_ENTRY = '1';
    const char REMOVE_ENTRY = '2';
    const char EDIT_ENTRY = '3';
    const char PRINT_ALL_ENTRIES = '4';
    const char CLEAR_ALL_ENTRIES = '5';

    const char SEARCH_ENTRY = '1';
    const char SAVE_TO_TXT = '2';
    const char SORT_ENTRIES = '3';
    const char SORT_BY_GROUP = '4';

    const char PREV_PAGE = '8';
    const char NEXT_PAGE = '9';
    const char QUIT = '0';
    //NOTE: sort by first name, last name, by phone number
    //NOTE: save as file txt
    //NOTE: protect with password 

    char chooseAction = PREV_PAGE; //to start the program
    string entryName, entryNumber;
    Entry newEntry {"unknown", "unknown"};
    int page_number = 1, max_page = 2;
    bool notQuit = true;

    vector <Entry> entryList {{"Alvin Levenson", "(487) 417-0829"}, {"Ben Balake", "(743) 395-1377"}, {"Chris Brown", "(357) 679-3200"}, {"Chris MyAss", "(803) 563-1534"}, {"David Copperfield", "(793) 497-9775"}, {"Emilia Mayweather", "(743) 796-6980"}}; 
    
    // mot so may khong chay duoc?
    // _setmode(_fileno(stdin), 0x00020000);
    // _setmode(_fileno(stdout), 0x00020000);

    while(notQuit) {
        if (chooseAction == PREV_PAGE || chooseAction == NEXT_PAGE) {
            system("cls");
            if (chooseAction == PREV_PAGE && page_number != 1) {
                page_number--;
            }
            else if (chooseAction == NEXT_PAGE && page_number != max_page) {
                page_number++;
            }
            switch(page_number) {
                case 1: {
                    cout << "\t1. Add an entry\n";
                    cout << "\t2. Remove an entry\n";
                    cout << "\t3. Edit an entry\n";
                    cout << "\t4. Print all entries\n";
                    cout << "\t5. Clear all entries\n";     
                    break;
                }
                case 2: {
                    cout << "\t1. Search all entries\n";
                    cout << "\t2. Save to TXT\n";
                    cout << "\t3. Sort entries\n";
                    cout << "\t4. Sort by group\n";
                    break;
                }
            }
            cout << endl;
            cout << "\t8. Previous Page\n";
            cout << "\t9. Next Page\n";
            cout << "\t0. QUIT\n";
            cout << "\t------------------\n";
        }

        if (page_number == 1) {
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
                    if(askToConfirm() == true) {
                        entryList.clear();
                        cout << "\tContact list deleted.\n";
                    }
                    //NOTE: confirm before deleting
                    break;
                }
                case QUIT: {
                    exit(0);
                }
        }}

        else if (page_number == 2) {
            cout << "Choose Action: ";
            cin >> chooseAction;
            switch(chooseAction) {
                default: {
                    cin.ignore(256, '\n');
                    break;
                }
                case SEARCH_ENTRY: {
                    string searchQuery;
                    bool foundResult = false;

                    fflush(stdin);
                    cout << "\tSearch: ";
                    getline(cin, searchQuery);

                    for (auto i : entryList) {
                        //NOTE: clean the code, count the time search Query appear then print out in the that order. 
                        //NOTE: maybe add search by first name, last name, ...?
                        //NOTE: search and edit/delete?
                        printSearchResults(i, searchQuery, foundResult);
                    }
                    if (foundResult == false) { //NOTE: maybe put the cout 
                        cout << "\tNo result found.\n";  
                    }
                    break;
                }
                case SAVE_TO_TXT:
                case SORT_ENTRIES:
                case SORT_BY_GROUP:
                    break;
                case QUIT: {
                    exit(0);
                }
            }
        }
        cout << endl;   
    }
    return 0;
}

void printAllEntries(vector <Entry> &entries) {
    if (!entries.empty()) {
        int list_count = 1;
        //NOTE: line up when print out. OR keep a space at the beginning of the program to show contact.
        for (auto i : entries) {
            cout << "\t" << list_count << ". ";
            i.printInfo();
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

void printSearchResults(Entry &entryElem, string &searchQuery, bool &foundResult) {
    //chuyen search query va thong tin trong danh ba thanh lower case de de tim.
    string lowerName = stringToLower(entryElem.name);
    string lowerSearchQuery = stringToLower(searchQuery);

    if ((lowerName.find(lowerSearchQuery) != -1) || (entryElem.getNumber().find(searchQuery) != -1)) {
        cout << "\t";
        entryElem.printInfo();
        foundResult = true;
    }
}

bool askToConfirm() {
    char confirm = 'n';
    cout << "Are you sure? (y/n) ";
    cin >> confirm;
    if (confirm == 'y') return true;
    return false;
}