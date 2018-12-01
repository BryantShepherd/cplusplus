#include <iostream>
#include <string>
using namespace std;
int main() {
    char myName[] = "hello";
    cout << myName << endl;
    // myName = "bonor"; khong gan lai theo cach nay duoc
    myName[5] = 'f';
    cout << myName << endl;

    return 0;
}