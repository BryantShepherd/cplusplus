#include <iostream>
<<<<<<< HEAD
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
=======
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
int main ()
{
    cout << M_PI << endl;
    return 0;
}
>>>>>>> 60ec1b860d60ad5c9f02918bba52d8b3af59f446
