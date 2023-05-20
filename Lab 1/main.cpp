#include <iostream>
#include "task.h"

std::string complexToString(complexNumber num) {
    std::string result = "z = ";
    result += std::to_string(num.Re);
    result += " + (";
    result += std::to_string(num.Im);
    result += ")i";

    return result;
}

std::string matrixToString(matrix myMatrix) {
    std::string result = "\n";
    int rows = 3;
    int cols = 3;

    for (int i = 0; i < rows; ++i) {
        result += "( ";
        for (int j = 0; j < cols; ++j) {
            result += std::to_string(myMatrix.data[i][j]);
            result += ' ';
        }
        result += ")\n";
    }

    return result;
}

void check2(double first, double second, double mem) {
    if (first == mem + second) {
        std::cout << first << " is ok\n";
    } else {
        std::cout << first << "\tis NOT ok\n";
    }
}

void check7(double number, double mem) {
    if (number == -mem) {
        std::cout << number << " is ok\n";
    } else {
        std::cout << number << "\tis NOT ok\n";
    }
}

void check10(complexNumber num, complexNumber mem) {
    if (num.Re == mem.Re && num.Im == -mem.Im) {
        std::cout << complexToString(num) << " is ok\n";
    } else {
        std::cout << complexToString(num) << " is NOT ok\n";
    }
}

void check15(matrix myMatrix, double multi, matrix mem) {
    bool result = true;
    int rows = 3;
    int cols = 3;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (myMatrix.data[i][j] != mem.data[i][j] * multi) {
                result = false;
                break;
            }
        }
    }

    if (result) {
        std::cout << matrixToString(myMatrix) << "is ok\n";
    } else {
        std::cout << matrixToString(myMatrix) << "is NOT ok\n";
    }
}

int main() {
// 2
    double first = 12;
    double second = 10;
    double mem2 = first;

    std::cout << "[2]\tIncreasing the value of " << first << " by " << second << ":\n";

    firstRef(first, second);
    check2(first, second, mem2);

    first = mem2;

    firstPtr(&first, second);
    check2(first, second, mem2);
// 7
    double number = 12;
    double mem7 = number;

    std::cout << "\n[7]\tChanging sign of " << number << ":\n";

    secondRef(number);
    check7(number, mem7);

    number = mem7;

    secondPtr(&number);
    check7(number, mem7);
// 10
    complexNumber complex{2, 3};
    complexNumber mem10 = complex;

    std::cout << "\n[10]\tFinding complex conjugate for " << complexToString(complex) << ":\n";

    thirdRef(complex);
    check10(complex, mem10);

    complex = mem10;

    thirdPtr(&complex);
    check10(complex, mem10);
// 15
    matrix myMatrix{1, 1, 1, 1, 1, 1, 1, 1, 1};
    double multi = 12.5819;
    matrix mem15 = myMatrix;

    std::cout << "\n[15]\tMultiplying a 3x3 matrix "
              << matrixToString(myMatrix) << "by a real number " << multi << "\n";

    fourthRef(myMatrix, multi);
    check15(myMatrix, multi, mem15);

    myMatrix = mem15;

    fourthPtr(&myMatrix, multi);
    check15(myMatrix, multi, mem15);

    return 0;
}

