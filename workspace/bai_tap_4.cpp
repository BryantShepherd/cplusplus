#include <iostream>
#include <string>
using namespace std;
int division(double a, double b) {
    if (b == 0) throw invalid_argument("divide by zero");
    return a/b;
}
int main() {
    try {
       cout << division(10, 0);
    }
    catch(...) {
        cout << "no" << endl;
    }
    return 0;
}