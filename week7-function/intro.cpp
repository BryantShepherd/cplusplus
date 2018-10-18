#include <iostream>
#include <tuple>
using namespace std;
/*
- Co 3 cach de truyen tham so cho ham.
 + pass-by-value: chi truyen gia tri cho tham so, vi vay thay doi tham so se khong anh huong den bien ban dau.
 + pass-by-reference: 
 + pass-by-address
*/
#include <iostream>
using namespace std;

long factorial(int n) {
    // complete the function
    if (n > 1) {
        return n * factorial(n-1);
    }
}

int main() {
    int N;
    cin >> N;
    cout << factorial(N);
    return 0;
}