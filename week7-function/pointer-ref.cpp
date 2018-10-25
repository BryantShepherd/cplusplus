#include <iostream>
using namespace std;
void addOne(int &number) {
    number++;
}
int main() {
    int number = 20;
    int *pointer;
    *pointer = number;

    cout << number << endl;
    cout << pointer << endl;
    cout << *pointer << endl;
    addOne(number);
    cout << number << endl << *pointer << endl;

    return 0;
}