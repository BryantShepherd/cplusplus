#include <iostream>
using namespace std;
int tong_le(int n) {
    if (2*n + 1 > 1) return 2*n + 1 + tong_le(n - 1);
    else return 1; //neu 2n + 1 = 1, can co de dung ham de quy.
        
}
int main() {
    int n;
    cin >> n;
    cout << tong_le(n);
    return 0;
}