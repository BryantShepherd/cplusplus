#include <iostream>
#include <string>
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
	//i la so chu so
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

int main() {
    int user_input, a;
	cout << "Nhap so chu so can kiem tra: ";
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> user_input;
        cout << tim_min(user_input) << endl;
    }
    return 0;
}