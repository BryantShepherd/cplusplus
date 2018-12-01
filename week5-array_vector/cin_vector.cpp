#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector <int> a;
    for (int i; cin >> i; ) { //terminate khi nhap vao gia tri khong phai int
        a.push_back(i);
    }
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << endl;
    }
    return 0;
}