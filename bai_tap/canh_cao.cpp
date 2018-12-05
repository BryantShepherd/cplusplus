#include <iostream>
using namespace std;
int main() {
    int so_nguoi;
    cin >> so_nguoi;
    char luot_an[so_nguoi];
    for (int i = 0; i < so_nguoi; i++) {
        cin >> luot_an[i];
    }
    int canh_cao = 0;
    int count;
    for (int i = 1; i < so_nguoi; i++) {
        count = 0;
        cout << "Luot thu " << i << ": " << luot_an[i] << endl;
        for (int j = 0; j < i; j++) { //Kiem tra xem nguoi vua an da an bao nhieu mieng roi
            if (luot_an[j]==luot_an[i]) count++;    
        }
        if (count > 0.5*i) { //neu nguoi do an duoc nhieu mieng hon nhung nguoi khac + lai, canh cao.
            canh_cao++;
            cout << "Canh bao" << endl;
        }
    }
    cout << "So canh cao la:" << canh_cao;
}