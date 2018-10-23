#include <iostream>
using namespace std;
int main() {
	int m, n;
	cin >> m >> n;
	int matrix[m + 1][n];
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	int gia_tri_chen, hang_chen;
	cin >> hang_chen >> gia_tri_chen;

    //chuyen vi tri cac hang
	for (int i = m; i > hang_chen - 1; i--) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = matrix[i - 1][j]; 
		}
	}

	for (int j = 0; j < n; j++) {
        matrix[hang_chen - 1][j] = gia_tri_chen;
    }

    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

	return 0;
}