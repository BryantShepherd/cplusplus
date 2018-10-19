#include <iostream>
#include <math.h>
using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int so_phan_tu, min_index, min_index_2, min_pos = -1;
	cin >> so_phan_tu;
	int list_so[so_phan_tu];
	for (int i = 0; i < so_phan_tu; i++) {
		cin >> list_so[i];
	}
    //sap xep so chan
    for (int i = 0; i < so_phan_tu; i++) {
        if (list_so[i] % 2 == 0) {
            min_index = i;
            min_pos++;
            
        }
        else {
            continue;
        }
        for (int j = i + 1; j < so_phan_tu; j++) {
            if (list_so[j] < list_so[min_index] && list_so[j] % 2 == 0) {
                min_index = j;
            }
        }
        
        swap(list_so[min_index], list_so[min_pos]);
    }

    // //sap_xep_so_le
    // for (int i = so_phan_tu - 1; i >= 0; i--) {
    //     if (list_so[i] % 2 == 1) {
    //         min_index = i;
    //     }
    //     else {
    //         break;
    //     }
    //     for (int j = i - 1; j >= 0; j--) {
    //         if (list_so[j] < list_so[min_index] && list_so[j] % 2 == 1) {
    //             min_index = j;
    //         }
    //     }
    //     swap(list_so[i], list_so[min_index]);
    // }



    //in ket qua
	for (int i = 0; i < so_phan_tu; i++) {
		cout << list_so[i] << " ";
	}
	return 0;    
}

