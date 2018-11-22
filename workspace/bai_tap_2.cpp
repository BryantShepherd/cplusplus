#include <iostream>
#include <vector>
using namespace std;

int getSum(vector<int> numbers)
{
    int sum = 0;
    for (int i: numbers)
        sum = sum + i;
    return sum;
}

int main()
{
    vector <int> a;
    a.push_back(10);
    a.push_back(20);
    cout << a[0] << endl;
    cout << getSum(a) << endl;
    return 0;
    
}