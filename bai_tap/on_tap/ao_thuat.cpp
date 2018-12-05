#include <iostream>
using namespace std;
int main() {
    int hang_p4, cot_p4;
    cin >> hang_p4 >> cot_p4;
    char la_bai[hang_p4*2][cot_p4*2];

    //tao ra la bai
    for (int i = 0; i < hang_p4; i++) {
        for (int j = 0; j < cot_p4; j++) {
            cin >> la_bai[i][j];
            la_bai[i][cot_p4*2 - j - 1] = la_bai[i][j];
            la_bai[hang_p4*2 - i - 1][j] = la_bai[i][j];
            la_bai[hang_p4*2 - i - 1][cot_p4*2 - j - 1] = la_bai[i][j];
        }
    }

    //tao ra loi
    int loi_x, loi_y;
    cin >> loi_x >> loi_y;
    if (la_bai[loi_x - 1][loi_y - 1] == '#') la_bai[loi_x - 1][loi_y - 1] = '.';
    else la_bai[loi_x - 1][loi_y - 1] = '#';

    //in ra la bai
    for (int i = 0; i < hang_p4 * 2; i++) {
        for (int j = 0; j < cot_p4 * 2; j++) {
            cout << la_bai[i][j];
        }
        cout << endl;
    }
}