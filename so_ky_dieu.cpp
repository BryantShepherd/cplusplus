//a la so ky dieu neu a = hieu cua so lon nhat
//tao tu chu so cua a va so be nhat tao boi chu so cua a


#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <cstdlib>
#include <windows.h>
#include <math.h>
using namespace std;
int tim_min(int n) {
	int a[10];
	int i = 0;
	while (n > 0) {
		a[i] = n % 10;
		n = n / 10;
		i++;
	}
	//sap xep tim min
	for (int j = 0; j < i; j++) {
		int min_index = j;
		for (int k = j + 1; k < i; k++) {
			if (j == 0 && a[k] == 0) {
				continue;
			}
			if (a[k] < a[min_index]) {
				min_index = k;
			}
		}
		int tmp = a[j];
		a[j] = a[min_index];
		a[min_index] = tmp;
	}
	int so_min = 0;
	for (int j = 0; j < i; j++) {
		so_min += a[j] * pow(10, i - 1 - j);
	}
	return so_min;
}
int tim_max(int n) {
	int a[10];
	int i = 0;
	while (n > 0) {
		a[i] = n % 10;
		n = n / 10;
		i++;
	}
	//sap xep tim max
	for (int j = 0; j < i; j++) {
		int max_index = j;
		for (int k = j + 1; k < i; k++) {
			
			if (a[k] > a[max_index]) {
				max_index = k;
			}	
		}
		int tmp = a[j];
		a[j] = a[max_index];
		a[max_index] = tmp;
	}
	int so_max = 0;
	for (int j = 0; j < i; j++) {
		so_max += a[j]*pow(10, i - 1 - j);
	}
	return so_max;
}

int main()
{
	// int n, count = 0;
	// cout << "Nhap gioi han n: ";
	// cin >> n;
	// for (int i = 1; i < n; i++) {
	// 	if (i == tim_max(i) - tim_min(i)) {
	// 		cout << i << endl;
	// 		count++;
	// 	}
	// }
	// if (count == 0) {
	// 	cout << "Khong ton tai so ki dieu." << endl;
	// }
	cout << tim_min(890) << endl << tim_max(890);
	system("pause");
	return 0;
}

