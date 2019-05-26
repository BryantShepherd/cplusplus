#include <iostream>
using namespace std;

class abc
{
    private:
        int a = 100;
    public:
        abc()
        {
            a = 1000;
        }
        int getA(){
            a++;
            return a;
        }   
};

class bc : public abc
{
    private:
        char a;
};

int main()
{
    bc var = {'5'};
    cout << var.getA();
}

