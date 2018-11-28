/*
Xet mot chuoi ki tu nhap vao tu ban phim. Chuoi goi la manh neu co > 8 ki tu, co ca chu hoa, thuong va so.
Neu chuoi co duoi 4 ki tu hoac chua ki tu dac biet thi chuoi khong hop le. Con lai la chuoi yeu. Xet xem chuoi
vua nhap vao la chuoi gi.
*/
#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string mk;
    cin >> mk;
    bool co_hoa = false, co_thuong = false, co_so = false;
    if (mk.length() >= 4) {
        for (int i = 0; i < mk.length(); i++) {
            if ((mk[i] >= '0' && mk[i] <= '9') || (mk[i] >= 'a' && mk[i] <= 'z') || (mk[i] >= 'A' && mk[i] <= 'Z')) {
                if (mk[i] >= '0' && mk[i] <= '9') co_so = true;
                if (mk[i] >= 'a' && mk[i] <= 'z') co_thuong = true;
                if (mk[i] >= 'A' && mk[i] <= 'Z') co_hoa = true;
                continue;
            }
            else {
                cout << "khong hop le";
                return 0;
            }
        }
        if (mk.length() <= 8) cout << "yeu";
        else {
            if (co_hoa == true && co_so == true && co_thuong == true) cout << "manh";
            else cout << "yeu";
        }
    }    
    else {
        cout << "khong hop le";
    }
    return 0;
}