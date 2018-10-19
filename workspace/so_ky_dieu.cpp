#include <iostream>
#include <string>
using namespace std;
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
int main() {
    int so_phan_tu;
    cin >> so_phan_tu;
    int list[so_phan_tu];
    for (int i = 0; i < so_phan_tu; i++) {
        cin >> list[i];
    }

    //sap xep
    int min_index;
    for (int i = 0; i < so_phan_tu; i++) {
        min_index = i;
        for (int j = i + 1; j < so_phan_tu; j++) {
            if (list[j] < list[min_index]) {
                min_index = j;
            }
        } 
        swap(list[min_index], list[i]);
    }
    for (int i = 0; i < so_phan_tu; i++) {
        cout << list[i] << " ";
    }
}