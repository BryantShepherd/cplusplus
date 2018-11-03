#include <iostream>
using namespace std;
int main() {
    int number = 20;
    int& refnumber = number; //tao bien tham chieu, theo minh hieu thi ban chat giong number nhung khac ten.

    cout << "Gia tri cua bien number la "<< number << endl; //20
    cout << "Dia chi cua bien number la " << &number << endl; //0x61ff08
    cout << "Gia tri cua bien refnumber la " << refnumber << endl; //20
    cout << "Dia chi cua bien refnumber la " << &refnumber << endl; //0x61ff08

    refnumber = 100; //thay doi gia tri bien tham chieu
    cout << "Sau khi thay refnumber = 100: " << number << " " << refnumber << endl;
<<<<<<< HEAD
    // -> huu ich khi dung trong function
=======

    /*Nhu the nghia la, trong ham nhu nay...
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp
    }
    ...minh dang tao bien tham chieu tuong ung voi 2 bien nhap vao, va thay doi gia tri cua no
    */
>>>>>>> 4358fad8069d28f0f47c6a963a63d660f8df16da
}