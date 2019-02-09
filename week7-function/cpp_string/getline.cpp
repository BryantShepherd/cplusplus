#include <iostream>
using namespace std;
int main()
{
    char n;
    cin >> n;
    string name;
    cin.ignore(100, '\n'); //neu khong co dong nay khi enter ham getline se nhan '\n' va ket thuc luon.
    getline(cin, name);
    cout << n << " " << name;
    return 0;
}