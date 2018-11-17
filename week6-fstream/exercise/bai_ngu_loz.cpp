//DE BAI: Dung mot file input co dang nhu sau
//6 3 (spt1, spt2)
//3 5 7 6 9 10 (pt cua mang 1)
//3 5 10 (pt cua mang 2)
//xoa nhung phan tu mang 2 co trong mang 1. viet vao file output tung buoc. 

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
        exit(1); //phai su dung exit vi day la ham void, khong return duoc.
    }
    myFile.close();
}

void ghi_file(int pt_ghi, int xuong_dong) { //xuong_dong la bien de xem da den luc xuong dong hay chua
    ofstream myFile("D:\\Coding\\cplusplus\\week6-fstream\\exercise\\output.txt", fstream::app); //fstream::app de viet bo sung vao file, neu khong thi chuong trinh se overwrite file.
    myFile << pt_ghi << " ";
    if (xuong_dong == 1) myFile << endl; //khi xuong_don == 1 thi nhap vao endl;
}

void xoa(int *m1, int &a, int can_xoa) {
    //xoa phan tu trong array
    for (int i = can_xoa; i < a - 1; i++) m1[i] = m1[i + 1];
    
}

void xoa_phan_tu(int *m1, int *m2, int &a, int &b) {
    
    for (int i = 0; i < b; i++) {
        int da_xoa = 0;
        for (int j = 0; j < a; j++) {
            if (m1[j] == m2[i]) {
                
                xoa(m1, a, j); //m1.erase(m1.begin() + j)
                da_xoa++; //xoa 1 phan tu thi da_xoa++, de xac dinh so phan tu con lai
            
            }

        }
        a-= da_xoa; //tim so phan tu con lai

        for (int k = 0; k < a; k++) {
            if (k != a - 1) ghi_file(m1[k], 0);
            else ghi_file(m1[k], 1); //k = a - 1, xuong_dong se bang 1 de in endl vao trong output.txt
        }
    }
}
int main() {
    int spt_1 = 5, spt_2 = 5; //can khoi tao gia tri, khong thi se gap loi bad_array_new_length.
    // Khoi tao spt_1 = 10 thi duoc, con bang 0 thi deo?
    int *mang_1, *mang_2;
    mang_1 = new int[spt_1];
    mang_2 = new int[spt_2];
    doc_file(mang_1, mang_2, spt_1, spt_2);
    // for (int i = 0; i < spt_1; i++) cout << mang_1[i] << " ";
    // for (int i = 0; i < spt_2; i++) cout << mang_2[i] << endl;
    xoa_phan_tu(mang_1, mang_2, spt_1, spt_2);

    return 0;
}

//con mot so phan lien quan den con tro minh van chua hieu ro ban chat, can doc them.