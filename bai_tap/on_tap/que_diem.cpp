#include <iostream>
using namespace std;
int main() {
    int so_diem;
    cin >> so_diem;
    double len_hop, wid_hop;
    cin >> len_hop >> wid_hop;
    int diem;
    for (int i = 0; i < so_diem; i++) {
        cin >> diem;
        if (diem * diem <= len_hop*len_hop + wid_hop*wid_hop) cout << "DA" << endl;
        else cout << "NE" << endl;
    }
    return 0;
}
