#include<iostream>
#include<cstdlib>

using namespace std;

template <typename T>
//or: template <class T>
T add(T a, T b){
    return a + b;
}

int main()
{
    int x = 2, y = 3;
    cout << add(x, y) << endl;
    
    float a = 1.0, b = 3.5;
    cout << add(a, b) << endl;
    
    return 0;
}

//thay cho function overload