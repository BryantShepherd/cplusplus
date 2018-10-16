#include <iostream>
#include <windows.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/*viet theo cot
	[0,0]
	[1,0][1,1]
	[2,0][2,1][2,2]
	*/
	int so_dong;
	cin >> so_dong;
	int a[so_dong][so_dong];
	a[0][0] = 1;
	a [0][1] = 0;
	a[1][2]=0;
	for (int i = 1; i < so_dong; i++) {
		
		for (int j = i; j < so_dong; j++) {
			a[j][0] = 1;
			a[j][j] = 1;
			a[j][j + 1] = 0;
			a[j][i] = a[j - 1][i-1] + a[j - 1][i];	
		}
	}	
	
	for (int i = 0; i < so_dong; i++) {
		for (int j = 0; j <= i; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}