#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string newGroup;
    vector <string> allGroup {"Family", "Friend", "Work"};
    cout << "start reading" << endl;
    ifstream inFile("contact_list.txt");
    if (!inFile.is_open()) exit(0);
    while(!inFile.eof()) {
        inFile.ignore(256, '\n');
        inFile.ignore(256, '\n');
        getline(inFile, newGroup);
        if (find(allGroup.begin(), allGroup.end(), newGroup) != allGroup.end()) {
            cout << "Find one" << endl;
        }
    }
    return 0;
}