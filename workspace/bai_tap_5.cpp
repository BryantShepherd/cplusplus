#include <iostream>
#include <cmath>
#include <vector>
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
    void printCoordinate() {
        cout << x << "," << y << endl; 
    }
};

struct Triangle {
    Point A, B, C;
    double AB = A.getLength(B);
    double AC = A.getLength(C);
    double CB = C.getLength(B);

};
int main() {
    vector <Point> newList {{1,2}, {2,3}};
    Point diemA(1,2);
    Point diemB(3,4);
    for (auto i: newList) {
        i.printCoordinate();
    }
    cout << diemA.getLength(diemB);
    return 0;
}