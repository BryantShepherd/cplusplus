#include <iostream>
using namespace std;
int main() {
    int a=0;
    int* p;
    p=&a;
    cout<<p<<" "<<&p<<" "<<*p;
    return 0;
}