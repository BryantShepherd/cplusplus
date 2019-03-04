#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
    Point() {
        x = 0;
        y = 0;
    }
    Point(double _x, double _y) {
        x = _x;
        y = _y;
    }
    double getLength(Point otherPoint) {
        return sqrt((x - otherPoint.x)*(x - otherPoint.x) + (y - otherPoint.y)*(y - otherPoint.y));
    }
};

struct Triangle {
    Point A, B, C;
    double AB = A.getLength(B);
    double AC = A.getLength(C);
    double CB = C.getLength(B);

};
int main() {
    Point diemA(1,2);
    Point diemB(3,4);
    cout << diemA.getLength(diemB);
    return 0;
}