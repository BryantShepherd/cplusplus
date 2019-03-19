#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <ctime>
using namespace std;

struct Entry{
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
    void scanInfo() {
        cout << "Name: ";
        getline(cin, name);
        cout << "Number";
        getline(cin, number);
    }
    void printInfo() {
        cout << "Tao la: " << name << " " << number << " " << group << endl;
    }
    string getName() {
        return name;
    }
    string getNumber() {
        return number;
    }
};

void saveToNewFile(vector <Entry> &entries) {
    ofstream outfile("contact_list.txt");
    for (auto i : entries) {
        outfile << i.id << ". " << i.getName() << " - " << i.getNumber() << endl; 
    }
    outfile.close();
}

void loadFromFile(vector <Entry> &entries) {
    Entry newEntry;
    ifstream inFile("contact_list.txt");
    while(getline(inFile, newEntry.name)) {
        getline(inFile, newEntry.number);
        getline(inFile, newEntry.group);
        entries.push_back(newEntry);
    }
}

int main() {
    string a = "xello darkness myoldfriend xonesi";
    string c = "my dick is red";
    string search_query = "lo";
    // vector <Entry> entryList {{1, "Albert Einstein", "(487) 417-0829"}, {2, "Ben The Uncle", "(743) 395-1377"}, {3, "Chris Bruise", "(357) 679-3200"}, {4, "Chris MyAss And It's Beautiful", "(803) 563-1534"}, {5, "David Coolaid", "(793) 497-9775"}, {6, "Emilia Isbestgirl", "(743) 796-6980"}}; 
    vector <Entry> entryList;
    vector <int> vec{1,2,3,4,5,6,7};
    // saveToNewFile(entryList);
    loadFromFile(entryList);
    for (auto i : entryList) {
        i.printInfo();
    }
    int n = 0;
    
    return 0;
}