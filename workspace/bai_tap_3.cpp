#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
    string a;
    cin >> a;
    string a_copy = a;
    cout << a_copy.length()
    for (int i = 0; i < a.length(); i++) {
        if (a[i] <= 122 && a[i] >= 97) {
            a[i]-=32;
            a_copy.erase(a_copy.begin() + i);
        }

    }
    cout << a << " " << a_copy << endl;
    // if ((a.find(b) != std::string::npos) || a_copy == b) cout << "ok" << endl;
}