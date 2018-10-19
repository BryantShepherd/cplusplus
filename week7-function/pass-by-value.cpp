#include <iostream>
#include <tuple>
using namespace std;
//giá trị của tham trị được copy vào tham số --> Thay đổi các giá trị này trong hàm không ảnh hưởng đến giá trị ban đầu 
// cach duy nhat de thay doi gia tri la su dung return

void swap(int x, int y){
    int t = x; x = y; y = t;
    //x, y is destroyed here
}

int main(){
    int a = 2;
    int b = 3;
    swap(a, b); //a va b chuyen gia tri cua minh cho bien x va y, nen a va b khong bi thay doi
    cout << a << ", " << b;
}