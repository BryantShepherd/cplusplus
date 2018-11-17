//function overload la khi cta su dung cung mot ham so 
//voi tham so co so luong va kieu du lieu khac nhau.
#include <iostream>
using namespace std;
void printSomething(int a) {
    cout << a;
}

void printSomething(string a) { //khac kieu du lieu nhap vao
    cout << a;
}

void printSomething(float a) {
    cout << a;
    cout << "no" << endl;
}

void printSomething(double a) {// co float va double thi se lay double
    cout << a << endl;
    cout << "Hello" << endl;
}

int main() {
    printSomething(5);
    cout << endl;
    printSomething("Hello World!");
    cout << endl;
    printSomething(5.0);
    return 0;
}