#include <iostream>
<<<<<<< HEAD
#include <algorithm> // for std::swap, use <utility> instead if C++11
 

bool ascending(int x, int y)
=======
<<<<<<< HEAD
using namespace std;
int main() {
	int m, n;
	cin >> m >> n;
	int matrix[m][n];
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	
    int hang_xoa;
    cin >> hang_xoa;

    for (int i = hang_xoa - 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = matrix[i+1][j];
        }
    }

    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n; j++ ) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}
=======
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
int main ()
>>>>>>> d34420de2d913b6a891b04e5ea4ae24b29acd63b
{
    return x > y;
}

bool descending(int x, int y)
{
    return x < y;
}
<<<<<<< HEAD

//sort even numbers first by ascending orders
bool evensFirst(int x, int y)
{
    // if x is even and y is odd, x goes first (no swap needed)
    if ((x % 2 == 0) && !(y % 2 == 0))
        return false;
 
    // if x is odd and y is even, y goes first (swap needed)
    if (!(x % 2 == 0) && (y % 2 == 0))
        return true;
 
        // otherwise sort in ascending order
    return ascending(x, y);
}

void selectionSort(int *array, int size, bool (*comparisonFunc)(int, int))
{
    // Step through each element of the array
    for (int startIndex = 0; startIndex < size; ++startIndex)
    {
        int smallestIndex = startIndex;
 
        // Look for smallest element remaining in the array (starting at startIndex+1)
        for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
        {
            if (comparisonFunc(array[smallestIndex], array[currentIndex])) // COMPARISON DONE HERE
                // This is the new smallest number for this iteration
                smallestIndex = currentIndex;
        }
 
        // Swap our start element with our smallest element
        std::swap(array[startIndex], array[smallestIndex]);
    }
}


void printArray(int *array, int size)
{
    for (int index=0; index < size; ++index)
        std::cout << array[index] << " ";
    std::cout << '\n';
}


int main()
{
    int array[9] = { 3, 7, 9, 5, 6, 1, 8, 2, 4 };
 
    selectionSort(array, 9, descending);
    printArray(array, 9);
    
 
    selectionSort(array, 9, evensFirst);
    printArray(array, 9);
    
    return 0;
}
=======
>>>>>>> 60ec1b860d60ad5c9f02918bba52d8b3af59f446
>>>>>>> d34420de2d913b6a891b04e5ea4ae24b29acd63b
