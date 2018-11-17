#include <iostream>
using namespace std;
class complex {
    int real, imag;
    public:
        complex(int _real = 0, int _imag = 0) {
            real = _real;
            imag = _imag;
        }   
        void printComplex() {
            cout << real << " " << imag << endl;
        }
        complex operator + (complex const &otherComplex) { //su dung khi co phep cong giua 2 bien complex
            complex result;
            result.real = real + otherComplex.real;
            result.imag = imag + otherComplex.imag; 
            return result;
        }

};
int main() {
    complex so_phuc1(5, 6);
    complex so_phuc2(-2, 9);
    complex so_phuc_tong = so_phuc1 + so_phuc2;
    so_phuc_tong.printComplex();
    return 0;
}