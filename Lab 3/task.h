#ifndef INC_3_TASK_H
#define INC_3_TASK_H

#include <cmath>

// task 1

class Complex {
public:
    Complex(double re = 0, double im = 0) {
        Re = re;
        Im = im;
    }

    double getRe() const;

    double getIm() const;

    void setRe(double value);

    void setIm(double value);

    explicit operator double() const;

private:
    double Re;
    double Im;
};

Complex operator*(Complex lhs, double rhs);

Complex operator*(double lhs, Complex rhs);

Complex operator+(Complex lhs, Complex rhs);

Complex operator*(Complex lhs, Complex rhs);

// task 8

class FIFO {
public:
    FIFO() {
        for (int &i: array) {
            i = 0;
        }
    }

    void push(int value);

    int pop();

private:
    int tail{};
    int array[100]{};
};

void operator<<(FIFO &lhs, int value);

void operator>>(FIFO &lhs, int &num);

#endif //INC_3_TASK_H
