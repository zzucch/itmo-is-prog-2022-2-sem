#include <iostream>
#include "Swap.h"
#include "Array.h"

void check1() {
    std::cout << "[C] - Changing two variables' values (Swap):\n";

    std::string first = "first";
    std::string second = "second";

    Swap(first, second);

    std::cout << "first: " << first << '\n';
    std::cout << "second: " << second << '\n';
}

void check2() {
    std::cout << "\n[F] - Array with N elements of type T:\n";

    const int size = 5;
    Array<size, int> myArray{};

    myArray.setElement(1, 4);
    std::cout << myArray.getElement(1) << '\n';
    std::cout << myArray.getElement(10) << '\n';
}

int main() {
    check1();

    try {
        check2();
    } catch (ArrayException &exception) {
        std::cout << exception.getMessage();
    }

    return 0;
}

