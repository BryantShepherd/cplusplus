#include <iostream>
#include <string>
#include <vector>
// #include <io.h>
#include <fcntl.h>

using namespace std;

struct Entry{
    wstring name, number;
    
    Entry() {
        name = L"unknown"; //Phai co L o truoc?
        number = L"unknown";
    }
    Entry(wstring _name, wstring _number) {
        name = _name;
        number = _number;
    }
    //should I use function, or just cin >> entry.name?
    void scanName() {
        fflush(stdin); //cin.ignore(), sap dung getline nen can xoa cache
        wcout << "\tName: ";
        getline(wcin, name);
    }
    void scanNumber() {
        fflush(stdin);
        wcout << "\tNumber: ";
        getline(wcin, number);
    }
    void printInfo() {
        wcout << "Name: " << name << "\tNumber: " << number << endl;
    }
    wstring getName() {
        return name;
    }
    wstring getNumber() {
        return number;
    }
};

void printAllEntries(vector <Entry> &entries);
wstring stringToLower(wstring a);
void printSearchResults(Entry &entryElem, wstring &searchQuery, bool &foundResult);
bool askToConfirm();

int main() {
    const wchar_t ADD_ENTRY = '1';
    const wchar_t REMOVE_ENTRY = '2';
    const wchar_t EDIT_ENTRY = '3';
    const wchar_t PRINT_ALL_ENTRIES = '4';
    const wchar_t CLEAR_ALL_ENTRIES = '5';

    const wchar_t SEARCH_ENTRY = '1';
    const wchar_t SAVE_TO_TXT = '2';
    const wchar_t SORT_ENTRIES = '3';

    const wchar_t PREV_PAGE = '8';
    const wchar_t NEXT_PAGE = '9';
    const wchar_t QUIT = '0';
    //NOTE: sort by first name, last name, by phone number
    //NOTE: save as file txt
    //NOTE: protect with password 

    wchar_t chooseAction = PREV_PAGE; //to start the program
    wstring entryName, entryNumber;
    Entry newEntry {L"unknown", L"unknown"};
    int page_number = 1, max_page = 2;
    bool notQuit = true;

    vector <Entry> entryList {{L"Alvin Levenson", L"(487) 417-0829"}, {L"Ben Balake", L"(743) 395-1377"}, {L"Chris Brown", L"(357) 679-3200"}, {L"Chris MyAss", L"(803) 563-1534"}, {L"David Copperfield", L"(793) 497-9775"}, {L"Emilia Mayweather", L"(743) 796-6980"}, {L"Nguyễn Tiến Đạt", L"(815)421-2203"}};
    
    //NOTE: divide into sections of choices. Press More to show more option. 
    
    //use Vietnamese characters
    // _setmode(_fileno(stdin), _O_U16TEXT);
    // _setmode(_fileno(stdout), _O_U16TEXT);

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
                    wcout << "\t1. Add an entry\n";
                    wcout << "\t2. Remove an entry\n";
                    wcout << "\t3. Edit an entry\n";
                    wcout << "\t4. Print all entries\n";
                    wcout << "\t5. Clear all entries\n";     
                    break;
                }
                case 2: {
                    wcout << "\t1. Search all entries\n";
                    wcout << "\t2. Save to TXT\n";
                    wcout << "\t3. Sort entries\n";
                    break;
                }
            }
            wcout << endl;
            wcout << "\t8. Previous Page\n";
            wcout << "\t9. Next Page\n";
            wcout << "\t0. QUIT\n";
            wcout << "\t------------------\n";
        }

        if (page_number == 1) {
            wcout << "Choose Action: ";
            wcin >> chooseAction; 
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

                    wcout << "Erase element (-1 to back): ";
                    wcin >> deleteElem;
                    if (deleteElem == -1 || deleteElem > entryList.size()) break;
                    entryList.erase(entryList.begin() + deleteElem - 1);
                    break;
                }
                case PRINT_ALL_ENTRIES: {
                    //NOTE: keep the contact in a file.
                    wcout << "All entries: " << endl;
                    printAllEntries(entryList);
                    break;
                }
                case EDIT_ENTRY: {
                    int editElem;
                    printAllEntries(entryList);
                    wcout << "Edit element (-1 to back): ";
                    //NOTE: check if user want to edit one or both info
                    wcin >> editElem;
                    if (editElem == -1 || editElem > entryList.size()) break;

                    entryList[editElem - 1].scanName();
                    entryList[editElem - 1].scanNumber();
                    break;
                }
                case CLEAR_ALL_ENTRIES: {
                    if(askToConfirm() == true) {
                        entryList.clear();
                        wcout << "\tContact list deleted.\n";
                    }
                    //NOTE: confirm before deleting
                    break;
                }
                case QUIT: {
                    exit(0);
                }
        }}

        else if (page_number == 2) {
            wcout << "Choose Action: ";
            wcin >> chooseAction;
            switch(chooseAction) {
                default: {
                    cin.ignore(256, '\n');
                    break;
                }
                case SEARCH_ENTRY: {
                    wstring searchQuery;
                    bool foundResult = false;

                    fflush(stdin);
                    wcout << "\tSearch: ";
                    getline(wcin, searchQuery);

                    for (auto i : entryList) {
                        //NOTE: clean the code, count the time search Query appear then print out in the that order. 
                        //NOTE: maybe add search by first name, last name, ...?
                        //NOTE: search and edit/delete?
                        printSearchResults(i, searchQuery, foundResult);
                    }
                    if (foundResult == false) { //NOTE: maybe put the cout 
                        wcout << "\tNo result found.\n";  
                    }
                    break;
                }
                case SAVE_TO_TXT:
                case SORT_ENTRIES:
                    break;
                case QUIT: {
                    exit(0);
                }
            }
        }
        wcout << endl;   
    }
    return 0;
}

void printAllEntries(vector <Entry> &entries) {
    if (!entries.empty()) {
        int list_count = 1;
        //NOTE: line up when print out. OR keep a space at the beginning of the program to show contact.
        for (auto i : entries) {
            wcout << "\t" << list_count << ". ";
            i.printInfo();
            list_count++;
        }
    }
    else {
        wcout << "\tContact list is empty.\n";
    }
    
}

wstring stringToLower(wstring a) {
    for (int i = 0; i < a.size(); i++) {
        a[i] = tolower(a[i]);
    }
    return a;
}

void printSearchResults(Entry &entryElem, wstring &searchQuery, bool &foundResult) {
    //chuyen search query va thong tin trong danh ba thanh lower case de de tim.
    wstring lowerName = stringToLower(entryElem.name);
    wstring lowerSearchQuery = stringToLower(searchQuery);

    if ((lowerName.find(lowerSearchQuery) != -1) || (entryElem.getNumber().find(searchQuery) != -1)) {
        wcout << "\t";
        entryElem.printInfo();
        foundResult = true;
    }
}

bool askToConfirm() {
    wchar_t confirm = 'n';
    wcout << "Are you sure? ";
    wcin >> confirm;
    if (confirm == 'y') return true;
    return false;
}