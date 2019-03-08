// #include <bits/stdc++.h>
#include <iostream>
#include <vector> //can de su dung vector
#include <algorithm> //chua ham sort; min, max; swap; reverse
using namespace std;

int main() {
    vector <int> example; //khai bao mang dong
    int a;
    for (int i = 0; i < 3; i++) {
        cin >> a;
        example.push_back(a); //them gia tri a vao cuoi array
    }
    // sort(example.begin(), example.end()); //sort(example, example + n)
    // reverse(example.begin(), example.end());
    // cout << example[0] << " " << example[2];
    for (auto i:example) {
        cout << i << endl;
    }
    return 0;
} 