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
    string a = "hellodarknessmyoldfriendlonesi";
    string search_query = "lo";
    int n = 0;
    while(n != -1) {
        n = a.find(search_query, n + search_query.size());
        cout << n << endl;
    }

    return 0;
}