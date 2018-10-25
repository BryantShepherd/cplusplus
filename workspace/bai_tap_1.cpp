#include <iostream>
using namespace std;
int main() {
	int m, n;
	cin >> m >> n;
	int matrix[m][n+1];
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	int gia_tri_chen, cot_chen;
	cin >> cot_chen >> gia_tri_chen;

	for (int i = 0; i < m; i++) {
		for (int j = n; j > cot_chen - 1; j--) {
			matrix[i][j] = matrix[i][j - 1]; 
		}
	}

	for (int i = 0; i < m; i++) {
		matrix[i][cot_chen - 1] = gia_tri_chen;
		for (int j = 0; j < n + 1; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}