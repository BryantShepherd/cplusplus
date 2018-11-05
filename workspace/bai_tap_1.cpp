#include <iostream>
using namespace std;
void in_tu(string a, int n, int max) {
    for (int j = n; j <= max; j++) {
        cout << a[j];
    }
    cout << " ";
}
int main()
{
    string a;
    getline(cin, a);
    int max = a.length() - 1; 
    for (int i = max; i >= 0; i--) {
        if ((a[i - 1] == ' ' && a[i] != ' ') || i == 0) {
            in_tu(a, i, max);
            max = i - 2;
        }
    }
}
