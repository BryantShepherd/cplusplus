#include <iostream>
#include <string>
using namespace std;
void addOne(int &y){// y là biến tham chiếu
    y = y + 1;
    // không cần return!
} //y is destroyed here

int main()
{
    int value = 5;
    cout << "value = " << value << "\n";
    addOne(value);
    cout << "value = " << value << "\n";
    return 0;
}