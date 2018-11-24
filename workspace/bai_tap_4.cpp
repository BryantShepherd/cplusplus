#include <iostream>
using namespace std;
<<<<<<< HEAD

int main() {

=======
int main() {
    int a[13] = {9, 8, 7, 1, 2, 8, 7, 5, 6, 9, 11, 12, 1};
    int max = 1;
    int len = 1;
    int vi_tri = 0;
    int x = 0;
    for (int i = 0; i < 13; i++) {
        if (a[i] < a[i + 1]) {
            len++;
        }
        else {
            if (len > max) {
                max = len;
                vi_tri = i - len + 1;
            }
            len = 1;
        }
    }
    for (int i = vi_tri; i < vi_tri + max; i++) {
        cout << a[i] << " ";
    }
    return 0;
>>>>>>> deb73bdc1f1711f4ed2c92db924bdc8205e872e5
}