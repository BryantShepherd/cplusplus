#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

std::string to_format(const int number) {
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << number;
    return ss.str();
}

int main() {
    cout << (6/5) * 5 << endl;
}