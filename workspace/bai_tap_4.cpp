#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
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

string getAlias(string &a) {
    string alias;
    for (int i = 0; i < a.size(); i++) {
        if ((a[i-1] == ' ' && a[i] != ' ') || i == 0) {
            alias += a[i];
        }
    }
    return alias;
}

bool sortByName(string &input1, string &input2) {
    string alias1 = getAlias(input1);
    string alias2 = getAlias(input2);
    reverse(alias1.begin(), alias1.end());
    reverse(alias2.begin(), alias2.end());
    return alias1 < alias2;
}

int main() {
    string a = "xello darkness myoldfriend xonesi";
    string c = "my dick is red";
    string search_query = "lo";
    vector <int> vec{1,2,3,4,5,6,7};
    int n = 0;
    // for (int i = 0; i < a.size(); i++) {
    //     cout << i << ",";
    //     a[i] = toupper(a[i]);
    // }
    // cout << endl << a;
    cout << sortByName(a, c);
    return 0;
}