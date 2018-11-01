#include<iostream>

using namespace std;

struct SVector{
    double x;
    double y;
    
    SVector(double _x, double _y) { //CHUA BIET DE LAM GI
        x = _x;
        y = _y;
    }

    void print(){
        cout << "("<< x << ", " << y << ")\n";
    }

    void lay_du_lieu() {
        cin >> x >> y;
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
    //Khởi tạo dùng initialization list (BAT BUOC PHAI CO GIA TRI KHOI TAO VI MOT LY DO NAO DO...)
    SVector s = {1.0, 3.0};
    CVector c = {2.0, 5.0};
    s.lay_du_lieu();
    
    // Hoặc là dùng uniform initialization (C++11)
    //uniform initialization, C++11~
    // SVector s {1.0, 3.0};
    // CVector c {2.0, 5.0};
    
    //print vectors
    s.print(); //goi ham print trong struct SVector
    c.print();
    
    cout << "Struct: x="<< s.x << ", y=" << s.y << "\n"; //s.x la gia tri cua x trong
    
    cout << "Class: x= "<< c.x << ", y=" << c.y << "\n";
    
    return 0;
}