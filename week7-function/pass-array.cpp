#include <iostream>
using namespace std;
// void tim_so(int arr[]); Khi truyen array vao ham, ta truyen pointer cua no. Vay nen nhung thay doi voi array trong ham se anh huong den array trong main
void tim_so(int *arr);

int main() {
    int tap_hop[10] = {1, 6, 3, 2, 14, 20, 17, 103, 284, 5}; //can truyen array nay vao function
    tim_so(tap_hop);
    return 0;
}

void tim_so(int arr[]) {
    for (int i = 0; i < 10; i++) {
        if (arr[i] > 10) cout << "Tim thay " << arr[i] << endl;
    }
}