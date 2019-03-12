// INTEGER VECTOR EXAMPLE 
// CPP program to illustrate 
// Implementation of begin() function 
#include <iostream> 
#include <vector> 
using namespace std; 
  
int main() 
{ 
    // declaration of vector container 
    vector<int> myvector{ 1, 2, 3, 4, 5 }; 
  
    // using begin() to print vector 
    // for (auto it = myvector.begin(); 
    //      it != myvector.end(); ++it) 
    //     cout << ' ' << *it; 
    // return 0; 
    cout << *myvector.rbegin() << endl;
} 