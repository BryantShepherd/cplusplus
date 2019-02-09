#include <iostream>
#include <string>
using namespace std;
int main() {
    char myName[] = "hello";
    cout << myName << endl;
    // myName = "bonor"; khong gan lai theo cach nay duoc
    myName[5] = 'f';
    cout << myName << endl; //ket qua: (hellof@). Do khi khoi tao gia tri myName[5] la NULL de dung in, nhung do minh thay thanh 'f' nen chuong trinh in den het chuoi.

    return 0;
}