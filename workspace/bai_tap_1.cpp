#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
  int a[5] = {5, 4, 3, 2, 1};
	sort(a, a + 4);
	for (int i = 0; i < 5; i++) cout << a[i] << endl;
	return 0;
}