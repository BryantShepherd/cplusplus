
#include<iostream>
#include<string>
using namespace std;

class Square
{
    private:
        int length;
        int width;
    public:
        Square();
        Square(int lenIn, int widIn);
        int getLength();
        int getWidth();
};

Square::Square()
{
    length = 0;
    width = 0;
}

Square::Square(int lenIn, int widIn) //hai constructor co tham so khac nhau
{
    length = lenIn;
    width = widIn;
}

int Square::getLength()
{
    return length;
}

int Square::getWidth()
{
    return width;
}

int main()
{
    Square s1;
    Square s2(4,3);
    cout<<"s1 dimensions are: "<<s1.getWidth()<<","<<s1.getLength();
    cout<<"\ns2 dimensions are: "<<s2.getWidth()<<","<<s2.getLength();
    return 0;
}