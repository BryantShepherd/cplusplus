#include <iostream>

using namespace std;
int main() {
    double a, b, c;
    cin >> a >> b >> c;
    if ((a + b) > c && (b + c) > a && (a + c) > b) {

        if (a == b && b == c) {
            cout << "Tam giac deu.";
        }
        else if (a == b || b == c || a == c) {
            if (a*a + b*b == c*c || b*b + c*c == a*a || a*a + c*c == b*b) {
                cout << "Tam giac vuong can";
            }
            else {
                cout << "Tam giac can";
            }
        }
        else if (a*a + b*b == c*c || b*b + c*c == a*a || a*a + c*c == b*b) {
            cout << "Tam giac vuong.";
        }
        else {
            cout << "Tam giac thuong";
        }

    }
    else {
        cout << "Khong phai tam giac.";
    }
    return 0;
}