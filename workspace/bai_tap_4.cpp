#include <iostream>
using namespace std;
int main() {
	int m, n;
	cin >> m >> n;
	int matrix[m][n];
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	
    int hang_xoa;
    cin >> hang_xoa;

    for (int i = hang_xoa - 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = matrix[i+1][j];
        }
    }

    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n; j++ ) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}