#include <iostream>
#include <cstdlib>
#include <fstream>
#include <windows.h>
using namespace std;
int main() {
    ifstream myFile("D:\\Coding\\cplusplus\\week6-fstream\\vi_du.txt"); // khai bao bien myFile, can su dung dia chi cu the va thay '\' thanh '\\'
    if (!myFile.is_open()) {    //Kiem tra xem file co mo duoc khong
        cout << "Khong mo duoc file" << endl;
        exit(1);
    }
    string line;
    while(!myFile.eof()) {  //Neu chua doc het file tu lap lai
        getline(myFile, line); // ham getline de lay duoc ca dau cach, co the su dung nhu ham cin binh thuong. ignore, getline, mot so cai nua, ...
        cout << line << endl;
        Sleep(100);
    }

    return 0;
}