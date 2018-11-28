#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int convert(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        if (!(s[i] >= '0' && s[i] <= '9')) {
            throw invalid_argument("Invalid!");
        }
        else {
            sum+=pow(s[i] - 48, s.length() - 1 - i);
        }
    }
    return sum;
}

int main() {
    string a = "1391a24";
    int i;
    try {
        i = convert(a);
    } catch (invalid_argument e) {
        std::cout << e.what() << " -> ";
    }
    std::cout << i << std::endl;
    return 0;
}