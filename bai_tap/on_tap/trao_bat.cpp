#include <iostream>
using namespace std;
int main() {
    string di_chuyen;
    cin >> di_chuyen;
    int vi_tri = 1;
    for (int i = 0; i < di_chuyen.length(); i++) {
        
        switch (di_chuyen[i])
        {
            case 'A'/* constant-expression */:
                /* code */
                if (vi_tri == 1) vi_tri = 2;
                else if (vi_tri == 2) vi_tri = 1;
                break;

            case 'B'/* constant-expression */:
                /* code */
                if (vi_tri == 2) vi_tri = 3;
                else if (vi_tri == 3) vi_tri = 2;
                break;

            case 'C'/* constant-expression */:
                /* code */
                if (vi_tri == 1) vi_tri = 3;
                else if (vi_tri == 3) vi_tri = 1;
                break;

            default:
                break;
        }
    }
    cout << vi_tri;
}