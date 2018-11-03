#include <iostream>
using namespace std;
int main() {
    int number = 20;
<<<<<<< HEAD
=======

>>>>>>> 4358fad8069d28f0f47c6a963a63d660f8df16da
    int* pointer = &number; //khai bao con tro

    cout << number << endl; // in ra 20
    cout << pointer << endl; //in ra dia chi bien number
    cout << *pointer << endl; // in ra gia tri bien number(20)

    return 0;
}