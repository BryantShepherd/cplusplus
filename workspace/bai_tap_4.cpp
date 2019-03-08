#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stdlib.h>
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
    void scanInfo() {
        cout << "Name: ";
        getline(cin, name);
        cout << "Number";
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

int main() {
    vector <Entry> entryList;
    Entry newEntry("Tuấn Anh", "09019481");
    entryList.push_back(newEntry);
    cout << newEntry.name << " " << newEntry.number << endl;
    entryList[0].printInfo();
    return 0;
}