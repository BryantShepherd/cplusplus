#include <iostream>
using namespace std;
int gNum = 0;
bool returnTrue(){
    gNum+=2;
    return true;
}
int main() {
    if(returnTrue()) {
        cout << gNum;
    }
}