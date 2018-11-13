//Tim min, max cua 3 so a, b, c
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector <int> example; //khai bao mang dong
    int a;
    for (int i = 0; i < 3; i++) {
        cin >> a;
        example.push_back(a); //them gia tri a vao cuoi array
    }
    sort(example.begin(), example.end()); //sap xep theo thu tu be den lon tu begin den end
    cout << example[0] << " " << example[2]; 
    return 0;
}