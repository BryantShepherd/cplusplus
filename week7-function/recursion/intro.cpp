#include <iostream>
using namespace std;
int tong_le(int n) {
    while (2*n + 1  0) {
        return (2*n + 1) + tong_le(2*n - 1);    
    }
        
}
int main() {
    int n;
    cin >> n;
    cout << tong_le(n);
    return 0;
}