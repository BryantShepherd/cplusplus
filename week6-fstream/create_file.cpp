#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
    std::ofstream outfile("test.txt");
    vector <int> vec{1, 2, 9 ,3, 4, 5, 2, 18, 81, 21};
    for (auto i : vec) {
        outfile << i << " ";
    }
    outfile << "\nmy text here!" << std::endl;
    outfile.close();
    return 0;
}