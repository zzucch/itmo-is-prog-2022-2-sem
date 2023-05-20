#include <iostream>
#include "task.h"

std::string ComplexToString(Complex num) {
    std::string result = std::to_string(num.getRe());
    result += " + ";
    result += std::to_string(num.getIm());
    result += "i";

    return result;
}

void check1(Complex num, double var) {
    Complex tmp = num * var;

    std::cout << "complex * double:\n";

    if (tmp.getRe() == num.getRe() * var && tmp.getIm() == num.getIm() * var) {
        std::cout << ComplexToString(tmp) << "\tis ok\n";
    } else {
        std::cout << ComplexToString(tmp) << "\tis NOT ok\n";
    }
}

void check2(Complex num1, Complex num2) {
    Complex tmp = num1 + num2;

    std::cout << "\ncomplex + complex:\n";

    bool condition1 = tmp.getRe() == num1.getRe() + num2.getRe();
    bool condition2 = tmp.getIm() == num1.getIm() + num2.getIm();

    if (condition1 && condition2) {
        std::cout << ComplexToString(tmp) << "\tis ok\n";
    } else {
        std::cout << ComplexToString(tmp) << "\tis NOT ok\n";
    }
}

void check3(Complex num1, Complex num2) {
    Complex tmp = num1 * num2;

    std::cout << "\ncomplex * complex:\n";

    double re = num1.getRe() * num2.getRe() - num1.getIm() * num2.getIm();
    double im = num1.getRe() * num2.getIm() + num2.getRe() * num1.getIm();

    if (re == tmp.getRe() && im == tmp.getIm()) {
        std::cout << ComplexToString(tmp) << "\tis ok\n";
    } else {
        std::cout << ComplexToString(tmp) << "\tis NOT ok\n";
    }
}

void check4(Complex num) {
    auto tmp = double(num);

    std::cout << "\nlength of complex:\n";

    if (tmp == sqrt((num.getRe() * num.getRe()) + (num.getIm() * num.getIm()))) {
        std::cout << tmp << "\t\t\tis ok\n";
    } else {
        std::cout << tmp << "\t\t\tis NOT ok\n";
    }
}

void check5(FIFO &fifo, int num) {
    fifo << num;
    fifo << num + 12;

    int tmp;
    fifo >> tmp;

    if (tmp == num) {
        std::cout << tmp << "\tis ok\n";
    } else {
        std::cout << tmp << "\tis NOT ok\n";
    }

    fifo >> tmp;
}

void check6(FIFO &fifo, int num) {
    int tmp;

    fifo << num;
    fifo >> tmp;

    if (tmp == num) {
        std::cout << tmp << "\tis ok\n";
    } else {
        std::cout << tmp << "\tis NOT ok\n";
    }
}

int main() {
//    var 15 - 1, 8
//    1 - complex number
    std::cout << "[1] - Complex number\n";

    Complex number1(1, 2);
    Complex number2(2, 3);
    double var1 = 12.12;

    check1(number1, var1);
    check2(number1, number2);
    check3(number1, number2);
    check4(number1);

//    8 - FIFO
    std::cout << "\n[8] - FIFO\n";

    FIFO fifo;
    int num = 12;

    check5(fifo, num);
    check6(fifo, num);
    return 0;
}

