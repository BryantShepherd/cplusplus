#include <iostream>
#include <string>
using namespace std;
bool kiem_tra(string a, string b) {
    int k = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] >= 'a' && a[i] <= 'z') {
            a[i]-=32;
        }
        if (a[i] = b[k]) {
            k++;
            if (k == b.length()) return true;
        }

    }
    return false;
}
int main() {
    string a, b;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (kiem_tra(a, b)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}