#include <iostream>
using namespace std;
int main() {
    int number = 20;
    int& refnumber = number; //tao bien tham chieu, theo minh hieu thi ban chat giong number nhung khac ten.

    cout << "Gia tri cua bien number la "<< number << endl;
    cout << "Dia chi cua bien number la " << &number << endl;
    cout << "Gia tri cua bien refnumber la " << refnumber << endl;
    cout << "Dia chi cua bien refnumber la " << &refnumber << endl;

    refnumber = 100; //thay doi gia tri bien tham chieu
    cout << "Sau khi thay refnumber = 100: " << number << " " << refnumber << endl;
}