#include <iostream>
#include <stdexcept>

// Integer division, catching divide by zero.

inline int intDivEx (int numerator, int denominator) {
    if (denominator == 0)
        throw std::overflow_error("Divide by zero exception"); //neu mau so = 0, throw overflow_error
    return numerator / denominator;
}

int main (void) {
    int i = 42;

    try { //su dung try de dam bao an toan, neu co loi thi se catch
        i = intDivEx (10, 2);
    } catch (std::overflow_error e) {
        std::cout << e.what() << " -> ";
    }
    std::cout << i << std::endl;

    try {
        i = intDivEx (10, 0);
    } catch (std::overflow_error e) {
        std::cout << e.what() << " -> ";
    }
    std::cout << i << std::endl;

    return 0;
}