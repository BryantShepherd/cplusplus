#include <bits/stdc++.h>
using namespace std;
int main() {
    vector <int> example;
    int a;
    for (int i = 0; i < 3; i++) {
        cin >> a;
        example.push_back(a); //them gia tri a vao cuoi array
    }
    sort(example.begin(), example.end());
    cout << example[0] << " " << example[2];
    return 0;
}