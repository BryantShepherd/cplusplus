#include <iostream>
using namespace std;
int main() {
	int so_phan_tu, max_index;
	cin >> so_phan_tu;
	int list[so_phan_tu];
	for (int i = 0; i < so_phan_tu; i++) {
		cin >> list[i];
	}
	for (int i = 0; i < so_phan_tu; i++) {
		if (list[i] % 2 == 1) {
			max_index = i;
			for (int j = i + 1; j < so_phan_tu; j++) {
				if (list[j] % 2 == 1) {
					if (list[j] < list[max_index]) {
						max_index = j;
					}
				
				int tmp = list[max_index];
				list[max_index] = list[i];
				list[i] = tmp;
				}
			}
		}
	}
	for (int i = 0; i < so_phan_tu; i++) {
		cout << list[i] << " ";
	}
	return 0;
}