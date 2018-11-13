<<<<<<< HEAD
//Tim min, max cua 3 so a, b, c
#include <bits/stdc++.h>
=======
// #include <bits/stdc++.h>
#include <iostream>
#include <vector> //can de su dung vector
#include <algorithm> //chua ham sort; min, max; swap; reverse
>>>>>>> b0e5fadae633f05f0521e9d3f02d90b352644892
using namespace std;

int main() {
    vector <int> example; //khai bao mang dong
    int a;
    for (int i = 0; i < 3; i++) {
        cin >> a;
        example.push_back(a); //them gia tri a vao cuoi array
    }
<<<<<<< HEAD
    sort(example.begin(), example.end()); //sap xep theo thu tu be den lon tu begin den end
    cout << example[0] << " " << example[2]; 
=======
    sort(example.begin(), example.end()); //sort(example, example + n)
    cout << example[0] << " " << example[2];
>>>>>>> b0e5fadae633f05f0521e9d3f02d90b352644892
    return 0;
}