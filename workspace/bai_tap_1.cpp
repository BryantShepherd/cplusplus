#include <iostream>
#include <string>
#include <vector>
// #include <io.h>
// #include <fcntl.h>
// #include <stdio.h>
#include <algorithm>
#include <fstream>

using namespace std;
//load when start, save when exit
struct Entry{
    //add tag, to specify which group an entry belong to.
    int id;
    string name, number;
    string group;
    
    Entry() {
        id = 0;
        name = "unknown"; 
        number = "unknown";
    }
    Entry(int _id, string _name, string _number) {
        id = _id;
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
    void scanGroup() {
        fflush(stdin);
        cout << "\tGroup: ";
        getline(cin, group);
    }
    void printInfo() {
        cout << id << ". Name: " << name << "\n\t  Number: " << number << endl;
    }
    string getName() {
        return name;
    }
    string getNumber() {
        return number;
    }
    string getGroup() {
        return group;
    }
};

void printAllEntries(vector <Entry> &entries);
string stringToLower(string a);
void printSearchResults(Entry &entryElem, string &searchQuery, bool &foundResult);
bool askToConfirm();
bool compareLastName(Entry entry1, Entry entry2);
string getAlias(string &a); //lay ten viet tat (de sap xep danh ba)
void resetEntryId(vector <Entry> &entries);
void saveToFile(vector <Entry> &entries);
void loadFromFile(vector <Entry> &entries);
void searchAction(vector <Entry> &entries);

int main() {
    const char ADD_ENTRY = '1';
    const char REMOVE_ENTRY = '2';
    const char EDIT_ENTRY = '3';
    const char PRINT_ALL_ENTRIES = '4';
    const char CLEAR_ALL_ENTRIES = '5';

    const char SEARCH_ENTRY = '1';
    const char SORT_ENTRIES = '2';
    const char FILTER_BY_GROUP = '3';

    const char PREV_PAGE = '8';
    const char NEXT_PAGE = '9';
    const char QUIT = '0';
    //NOTE: protect with password 

    char chooseAction = PREV_PAGE; //to start the program
    Entry newEntry;
    int page_number = 1, max_page = 2;
    int deleteElem, editElem;
    bool notQuit = true;

    // vector <Entry> entryList {{1, "Alvin Levenson", "(487) 417-0829"}, {2, "Ben Balake", "(743) 395-1377"}, {3, "Chris Brown", "(357) 679-3200"}, {4, "Chris MyAss", "(803) 563-1534"}, {5, "David Copperfield", "(793) 497-9775"}, {6, "Emilia Mayweather", "(743) 796-6980"}}; 
    vector <Entry> entryList;
    loadFromFile(entryList);
    while(notQuit) {
        if (chooseAction != PREV_PAGE && chooseAction != NEXT_PAGE && chooseAction != QUIT) system("pause");
        system("cls");   

        if (chooseAction == QUIT) {
            saveToFile(entryList);
            cout << "Contact list saved to contact_list.txt" << endl;
            system("pause");
            exit(0);
        }
        
        if (chooseAction == PREV_PAGE || chooseAction == NEXT_PAGE) {
            if (chooseAction == PREV_PAGE && page_number != 1) {
                page_number--;
            }
            else if (chooseAction == NEXT_PAGE && page_number != max_page) {
                page_number++;
            }
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
                cout << "\t2. Sort entries\n";
                cout << "\t3. Filter by group\n";
                break;
            }
        }
        cout << endl;
        cout << "\t8. Previous Page\n";
        cout << "\t9. Next Page\n";
        cout << "\t0. QUIT\n";
        cout << "\t------------------\n";

        if (page_number == 1) {
            cout << "Choose Action: ";
            cin >> chooseAction; 
            system("cls");
            switch(chooseAction) {
                default: {
                    cin.ignore(256, '\n');
                    break;
                }
                case ADD_ENTRY: {
                    //Get user input
                    newEntry.id = entryList.size() + 1;
                    newEntry.scanName();
                    newEntry.scanNumber();
                    newEntry.scanGroup();

                    //Append to contact list
                    entryList.push_back(newEntry);
                    break;
                }
                case REMOVE_ENTRY: {
                    printAllEntries(entryList);

                    cout << "Erase element (-1 to back): ";
                    cin >> deleteElem;
                    if (deleteElem < 1 || deleteElem > entryList.size() || !cin) {
                        cin.clear();
                        cin.ignore(256, '\n');
                        break;
                    }  //!cin -> cin.clear()

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
                    printAllEntries(entryList);
                    cout << "Edit element (-1 to back): ";
                    //NOTE: check if user want to edit one or both info
                    cin >> editElem;
                    if (editElem < 1 || editElem > entryList.size() || !cin) {
                        cin.clear();
                        cin.ignore(256, '\n');
                        break;
                    }  

                    entryList[editElem - 1].scanName();
                    entryList[editElem - 1].scanNumber();
                    break;
                }
                case CLEAR_ALL_ENTRIES: {
                    if(askToConfirm() == true) {
                        entryList.clear();
                        cout << "\tContact list deleted.\n";
                    }
                    break;
                }
        }}

        else if (page_number == 2) {
            cout << "Choose Action: ";
            cin >> chooseAction;
            system("cls");
            switch(chooseAction) {
                default: {
                    cin.ignore(256, '\n');
                    break;
                }
                case SEARCH_ENTRY: {
                    string searchQuery;
                    int actionAfterSearch;
                    bool foundResult = false;

                    fflush(stdin);
                    cout << "\tSearch: ";
                    getline(cin, searchQuery);

                    for (auto i : entryList) { 
                        //NOTE: maybe add search by first name, last name, ...?
                        printSearchResults(i, searchQuery, foundResult);
                        
                    }
                    if (foundResult == false) {
                        cout << "\tNo result found.\n";  
                    }
                    searchAction(entryList); //choose search result and edit/remove
                    break;
                }
                case SORT_ENTRIES: {
                    //sort by?
                    sort(entryList.begin(), entryList.end(), compareLastName);
                    resetEntryId(entryList);
                    printAllEntries(entryList);
                    break;
                }
                case FILTER_BY_GROUP:
                    break;
            }
        }
        
    }
    return 0;
}

void printAllEntries(vector <Entry> &entries) {
    if (!entries.empty()) {
        //NOTE: line up when print out. OR keep a space at the beginning of the program to show contact.
        for (auto i : entries) {
            cout << "\t";
            i.printInfo();
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
    string lowerName = stringToLower(entryElem.getName());
    string lowerSearchQuery = stringToLower(searchQuery);

    if ((lowerName.find(lowerSearchQuery) != string::npos) || (entryElem.getNumber().find(searchQuery) != string::npos)) {
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

string getAlias(string &a) { //NOTE: careful with the input
    string alias;
    for (int i = 0; i < a.size(); i++) {
        if ((a[i-1] == ' ' && a[i] != ' ') || i == 0) {
            alias += toupper(a[i]);
        }
    }
    return alias;
}

bool compareLastName(Entry entry1, Entry entry2) {
    string input1 = entry1.getName(), input2 = entry2.getName();
    string alias1 = getAlias(input1);
    string alias2 = getAlias(input2);
    reverse(alias1.begin(), alias1.end()); //xep theo ten nen can reverse, xep theo ho thi khong can
    reverse(alias2.begin(), alias2.end());
    return alias1 < alias2;
}

void resetEntryId(vector <Entry> &entries) {
    for (int i = 0; i < entries.size(); i++) {
        entries[i].id = i + 1;
    }
}

void saveToFile(vector <Entry> &entries) {
    string fileName = "contact_list"; //neu muon them tinh nang save cac file khac nhau
    ofstream outFile(fileName + ".txt");
    if (!outFile.is_open()) {
        cout << "ERROR: cannot save to file." << endl;
    }
    else {
        for (auto i : entries) {
            outFile << i.getName() << endl << i.getNumber() << endl; 
        }
        outFile.close();
    }
}

void loadFromFile(vector <Entry> &entries) {
    string fileName = "contact_list";
    ifstream inFile(fileName + ".txt");
    if (!inFile.is_open()) {
        cout << "ERROR: cannot load from file." << endl;
    }
    else {
        while(!inFile.eof()) {
            Entry newEntry;
            newEntry.id = entries.size() + 1;
            getline(inFile, newEntry.name);
            if (newEntry.name == "") continue;
            getline(inFile, newEntry.number);
            entries.push_back(newEntry);
        }
        inFile.close();        
    }
}

void searchAction(vector <Entry> &entries) {
    const int EDIT_SEARCH_RESULT = 1;
    const int DEL_SEARCH_RESULT = 2;
    int elem, tmpChooseAction;
    cout << "\tChoose entry to edit/remove: ";
    cin >> elem;
    if (elem < 1 || elem > entries.size() || !cin) {
        cout << "ERROR: element out of range" << endl;
        cin.ignore(256, '\n');
    } 
    else {
        cout << "\t\t1. Edit entry" << endl;
        cout << "\t\t2. Remove entry" << endl;
        cout << "\n\t\t0. Back" << endl;
        cout << "\t\t Edit/remove: ";
        cin >> tmpChooseAction;
        switch(tmpChooseAction) {
            default: {
                cin.ignore(256, '\n');
                break;
            }
            case EDIT_SEARCH_RESULT: {
                cout << "\t";
                entries[elem - 1].scanName();
                cout << "\t";
                entries[elem - 1].scanNumber();
                break;
            }
            case DEL_SEARCH_RESULT: {
                cout << "\t" << entries[elem - 1].getName() << " deleted successfully!" << endl;
                entries.erase(entries.begin() + elem - 1);
                break;
            }
        }
    }
    
}