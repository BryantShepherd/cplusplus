#include <iostream>
#include <math.h>
using namespace std;
bool kiem_tra_nt(int n) {
    if (n == 2 || n == 3 || n == 5 || n == 7) {
        return true;
    }
    else {
        return false;
    }
}
int dem_cs_nt(int n) {
    int count = 0;
    while (n > 0) {
        if (kiem_tra_nt(n % 10) == true) {
            count++;
        }
        n = n / 10;
    }
    return count;
}
int main() {
    int a;
    cin >> a;
    int user_input;
    for (int i = 0; i < a; i++) {
        cin >> user_input;
        cout << dem_cs_nt(user_input) << endl;
    }
    return 0;
}