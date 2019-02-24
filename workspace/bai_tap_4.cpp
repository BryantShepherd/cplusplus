#include <iostream>
#include <cerrno>
#include <cmath>
#include <stdlib.h>
using namespace std;
int main() {
    const double PI = 3.14159265358979323846; 
    double a, b;
    cin >> a >> b;
    if (pow(a,b) == INFINITY) cout << "error" << endl;
    if (pow(a,b) == NAN) cout << "nanno" << endl;
    cout << pow(a, b) << endl;
    // if (errno) cout << "errno" << endl;
    // else if (errno == EDOM) cout << "domain error" << endl;
    // else if (errno == ERANGE) cout << "range error" << endl;

}