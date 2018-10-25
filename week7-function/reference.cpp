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
    // -> huu ich khi dung trong function
}