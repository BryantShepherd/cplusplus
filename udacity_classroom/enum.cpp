#include <iostream>
using namespace std;
int main() {
    enum Test
    {
        TEST1,
        TEST2,
        TEST3
    };

    enum Color
    {
        COLOR_BLACK = 10,
        COLOR_RED, 
        COLOR_BLUE, 
        COLOR_GREEN, 
        COLOR_WHITE,
        COLOR_CYAN,
        COLOR_YELLOW
    };
    // int COLOR_BLACK = 120; COLOR_BLACK LA GLOBAL SCOPE

    Color backgroundColor = COLOR_BLACK; 
    // Vay nen bien cua enum Color se chi duoc dat la 1 cai ten trong enum day thoi.
    cout << backgroundColor << endl;
    cout << COLOR_BLACK << endl;

}