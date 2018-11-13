#include <iostream>
using namespace std;
int main() {
  int number = 20;
  int *pointer = &number;
  *pointer = *pointer + 1;
  cout << number;
  return 0;
}