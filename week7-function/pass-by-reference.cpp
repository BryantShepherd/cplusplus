// Thay thế cho (1) pass-by-value và giải quyết:
// sao chép dữ liệu của tham trị
// sửa giá trị của tham trị
// Và có thể dùng để:
// trả lại nhiều giá trị cùng lúc (return multiple values via out parameters)
#include<iostream>
#include<cmath>

void getSinCos(double degrees, double &sinOut, double &cosOut){ //tao bien tham chieu sinOut va cosOut, roi sua doi 2 bien do.
    //std::sin() và std::cos() take radians
    // convert degree to radian
    const double pi = 3.14159265358979323846; // the value of pi
    double radians = degrees * pi / 180.0;
    sinOut = std::sin(radians);
    cosOut = std::cos(radians);
}

int main()
{
    double degree = 30.0;
    double sin(0.0);
    double cos(0.0);
    //getSinCos will return the sin and cos in variables sin and cos
    getSinCos(degree, sin, cos);
    std::cout << "The sin of " << degree << " degree is " <<
        sin << "\n";
    std::cout << "The cos of " << degree << " degree is " <<
        cos << "\n";
    
    return 0;
}