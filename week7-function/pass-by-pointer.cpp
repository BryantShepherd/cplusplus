#include <iostream>
using namespace std;
    
void square(int *);
    
int main() {
    int number = 8;
    cout <<  "In main(): " << &number << endl;  // 0x22ff1c
    cout << number << endl;   // 8
    square(&number);          // Truyền địa chỉ của biến thay vì truyền tên biến
    cout << number << endl;   // 64
}
    
void square(int * pNumber) {  // Hàm nhận đối số con trỏ
    cout <<  "In square(): " << pNumber << endl;  // 0x22ff1c
    *pNumber *= *pNumber;      // Thay đổi vào ô nhớ mà biến pNumber chỉ đến.
}       