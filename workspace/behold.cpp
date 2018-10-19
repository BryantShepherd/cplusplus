#include <iostream>
#include <math.h>
using namespace std;

string chuan_hoa(string a) {
    if (a[0] >= 'a' && a[0] <= 'z') {
        a[0] = a[0] - 32;
    } 
    for (int i = 1; i < a.length(); i++) {
        if (a[i] >= 'A' && a[i] <= 'Z') {
            a[i] = a[i] + 32;
        }
    } 
    return a;
}
int main() {
    string ten[3];
    for (int i = 0; i < 3; i++) {
        cin >> ten[i];
    }
    
    for (int i = 0; i < 3; i++) {
        cout << chuan_hoa(ten[i]) << " ";
    }
    return 0;
}