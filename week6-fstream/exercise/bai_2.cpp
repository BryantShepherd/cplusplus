#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
void doc_file(int *m1, int *m2, int &a, int &b) {
    ifstream myFile("D:\\Coding\\cplusplus\\week6-fstream\\exercise\\input.txt");
    if (myFile.is_open()) {
        myFile >> a >> b;
        // cout << a << " " << b << endl;
        for (int i = 0; i < a; i++) {
            myFile >> m1[i];
            // cout << m1[i] << " ";
        }
        for (int i = 0; i < b; i++) {
            myFile >> m2[i];
        }
    }
    else {
        cout << "Khong mo duoc";
        exit(1);
    }
    myFile.close();
}

// void ghi_file(int pt_ghi) {
//     ofstream myFile("D:\\Coding\\cplusplus\\week6-fstream\\exercise\\output.txt");
//     myFile << pt_ghi << " ";
// }
// void xoa_phan_tu(int *m1, int *m2, int &a, int &b) {

//     for (int i = 0; i < b; i++) {
//         int da_xoa = 0;
//         for (int j = 0; j < a; j++) {
//             if (m1[j] == m2[i]) {
//                 cout << "can xoa " << da_xoa << endl;
//                 da_xoa++;
//             }

//         }
//         // a-= da_xoa;
//         // for (int k = 0; k < a; k++) ghi_file(m1[k]);
        
//     }
// }
int main() {
    int spt_1, spt_2;
    int *mang_1, *mang_2;
    mang_1 = new int[spt_1];
    mang_2 = new int[spt_2];
    doc_file(mang_1, mang_2, spt_1, spt_2);
    cout << mang_1[2];
    // xoa_phan_tu(mang_1, mang_2, spt_1, spt_2);


}