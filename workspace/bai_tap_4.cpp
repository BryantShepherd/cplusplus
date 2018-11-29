#include <iostream>
#include <string>
using namespace std;
int division(double a, double b) {
    if (b == 0) error("loi chia cho khong");
    return a/b;
}
int main() {
    
    cout << division(10, 2);
    return 0;
}