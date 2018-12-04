#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector <int> day_so;
    int a, sum = 0;
    for (int i = 0; i < 9; i++) {
        cin >> a;
        day_so.push_back(a);
        sum+=a;
    }
    cout << sum << endl;
    for (int i = 0; i < day_so.size(); i++) {
        for (int j = i + 1; j < day_so.size(); j++) {
            if (sum - day_so[i] - day_so[j] == 100) {
                day_so.erase(day_so.begin() + j); //vi j > i nen phai xoa j truoc
                day_so.erase(day_so.begin() + i);
                break;
            }
        }
    }

    for (int i: day_so) cout << i << endl;
    return 0;
}