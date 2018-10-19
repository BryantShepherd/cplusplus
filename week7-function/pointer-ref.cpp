#include <iostream>
using namespace std;
int main() {
    int number = 20;
    int *pointer;
    *pointer = number;

    cout << number << endl;
    cout << pointer << endl;
    cout << *pointer << endl;
    return 0;
}