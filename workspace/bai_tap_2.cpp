#include <iostream>
#include <iomanip>
using namespace std;

float diem_tb_th (float *a) { //so phan tu cua a la 10
    
    for (int i = 0; i < 10; i++) {
        int max = i;
        for (int j = i; j < 10; j++) {
            if (a[j] > a[max]) {
                max = j;
            }
        }
        float tmp = a[i];
        a[i] = a[max];
        a[max] = tmp;
    }
    // for (int i = 0; i < 10; i++) {
    //     cout << a[i] << " ";
    // }

    float avg5 = (a[0] + a[1] + a[2] + a[3] + a[4])/5;
    return avg5;
}
int main() {
    int so_buoi;
    float diem_so[10];
    cin >> so_buoi;
    for (int i = 0; i < 10; i++) {
        cin >> diem_so[i];
    }
    diem_tb_th(diem_so); //sap xep diem thuc hanh
    float diem_gk[2];
    cin >> diem_gk[0] >> diem_gk[1];
    float diem_ck, diem_st;
    cin >> diem_ck >> diem_st;
    if (diem_so[4] == 0) cout << 0.0 << endl;
    else {
        float tk = diem_tb_th(diem_so)*0.2 + 0.1 * (diem_gk[0] + diem_gk[1]) + 0.6 * (diem_st + diem_ck);
        if (tk > 10.0) tk = 10.0;
        cout << fixed << setprecision(1) << tk << endl;
    }
    return 0;
}