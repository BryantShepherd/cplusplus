#include<iostream>

using namespace std;

struct SVector{
    double x;
    double y;
    
    SVector(double _x, double _y) {
        x = _x;
        y = _y;
    }
    
    void print(){
        cout << "("<< x << ", " << y << ")\n";
    }
};

class CVector{
    public: //chú ý là public 
        double x;
        double y;
    
    public:
        void print(){
            cout << "("<< x << ", " << y << ")\n";
        }
};

int main()
{
    //Khởi tạo dùng initialization list
    SVector s = {1.0, 3.0};
    CVector c = {2.0, 5.0};
    
    // Hoặc là dùng uniform initialization (C++11)
    //uniform initialization, C++11~
    // SVector s {1.0, 3.0};
    // CVector c {2.0, 5.0};
    
    //print vectors
    s.print();
    c.print();
    
    cout << "Struct: x="<< s.x << ", y=" << s.y << "\n";
    
    cout << "Class: x= "<< c.x << ", y=" << c.y << "\n";
    
    return 0;
}