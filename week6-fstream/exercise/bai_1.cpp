//doc tu file input.txt vao mot so nguyen duong, dao nguoc va ghi lai so dao vao file.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
using namespace std;
void doc_file(int *n) { //n la dia chi nen phai ghi la *n
    ifstream myFile("D:\\Coding\\cplusplus\\week6-fstream\\vi_du.txt");
    if (!myFile.is_open()) {
        cout << "Khong mo duoc file." << endl;
        exit(1);
    }
    else {
        while(!myFile.eof()) {
            myFile >> *n;
        }
    }
    myFile.close(); //khong co dong nay van chay duoc binh thuongm
}

int dao_nguoc(int *n) {
    int so_dao_nguoc = 0;
    int a = *n;
    while (a > 0) {
        so_dao_nguoc = so_dao_nguoc*10 + a % 10;
        a /= 10;
    }
    return so_dao_nguoc;
}

void ghi_file(int a) {
    ofstream myFile("D:\\Coding\\cplusplus\\week6-fstream\\vi_du.txt");
    if (!myFile.is_open()) {
        cout << "Khong mo duoc file." << endl;
        exit(1);
    }
    else {
        myFile << a;
        cout << "Thanh Cong!";
    }
}


int main() {
    int *n;
    n = new int;
//int a=0;
    doc_file(n);
    ghi_file(dao_nguoc(n));
    // delete n; xoa de tiet kiem bo nho?
    // n=NULL;
    return 0;
}
