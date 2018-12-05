#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    char bang[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> bang[i][j];
        }
    }
    bool thang = false;
    char nguoi_thang;
    for (int i = 0; i < n; i++) { //check den n thi co ve hoi qua
        for (int j = 0; j < n; j++) {
            if (bang[i][j] == bang[i + 1][j] && bang[i + 1][j] == bang[i + 2][j] && bang[i + 1][j] != '.'){
                thang = true;
                nguoi_thang = bang[i][j];
                break;    
            } 
            if (bang[i][j] == bang[i][j + 1] && bang[i][j + 1] == bang[i][j + 2] && bang[i][j + 1] != '.'){
                thang = true;   
                nguoi_thang = bang[i][j]; 
                break;
            } 
            if (bang[i][j] == bang[i + 1][j + 1] && bang[i + 1][j + 1] == bang[i + 2][j + 2] && bang[i + 1][j + 1] != '.'){
                thang = true;  
                nguoi_thang = bang[i][j];
                break;  
            } 
            if (bang[i][j] == bang[i + 1][j - 1] && bang[i + 1][j - 1] == bang[i + 2][j - 2] && bang[i + 1][j - 1] != '.'){
                thang = true;  
                nguoi_thang = bang[i][j];
                break;  
            }   
        }
    }
    if (thang == true) cout << nguoi_thang << " da chien thang." << endl;
    else cout << "game dang choi." << endl;
}