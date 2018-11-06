#include <iostream>
#include <string>
#include <math.h>
using namespace std;
struct fraction{
    int numerator, denominator;
    fraction(int _numerator, int _denominator) {
        numerator = _numerator;
        denominator = _denominator;
    }
    fraction addFrac(fraction b) { //add cai nay voi fraction b
        fraction x{1,1};
        x.numerator = numerator*b.denominator + b.numerator*denominator;
        x.denominator = denominator*b.denominator;
        int max;
        if (x.numerator > x.denominator) max = x.numerator;
        else max = x.denominator;
        for (int i = max; i > 1; i--) {
            if (x.denominator % i == 0 && x.numerator % i == 0) {
                x.denominator/=i;
                x.numerator/=i;
                return x;
            }
        }

    }
};


int main() {
    fraction a{1,1}, b{1,1};
    cin >> a.numerator >> a.denominator >> b.numerator >> b.denominator;
    cout << a.addFrac(b).numerator <<"/" << a.addFrac(b).denominator<< endl;

}