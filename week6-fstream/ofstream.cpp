#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ofstream o_file("D:\\Coding\\cplusplus\\week6-fstream\\vi_du.txt", ios::app);
    if (!o_file.is_open()) {
        cout << "Khong mo duoc file.";
        return 1;
    }
    else {
        string line;
        getline(cin, line);
        o_file << line;
        cout << "Success." << endl;
    }
    return 0;
}