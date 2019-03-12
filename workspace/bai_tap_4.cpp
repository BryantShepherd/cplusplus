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
    vector <int> vec{1,2,3,4,5,6,7};
    int n = 0;
    for (int i = 0; i < a.size(); i++) {
        cout << i << ",";
        a[i] = toupper(a[i]);
    }
    cout << endl << a;

    return 0;
}