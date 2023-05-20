#include "task.h"

// task 1

double Complex::getRe() const {
    return this->Re;
}

double Complex::getIm() const {
    return this->Im;
}

void Complex::setRe(double value) {
    this->Re = value;
}

void Complex::setIm(double value) {
    this->Im = value;
}

Complex operator*(Complex lhs, double rhs) {
    return {lhs.getRe() * rhs, lhs.getIm() * rhs};
}

Complex operator*(double lhs, Complex rhs) {
    return {rhs.getIm() * lhs, rhs.getIm() * lhs};
}

Complex operator+(Complex lhs, Complex rhs) {
    return {lhs.getRe() + rhs.getRe(), lhs.getIm() + rhs.getIm()};
}

Complex operator*(Complex lhs, Complex rhs) {
    double re = lhs.getRe() * rhs.getRe() - lhs.getIm() * rhs.getIm();
    double im = lhs.getRe() * rhs.getIm() + rhs.getRe() * lhs.getIm();
    return {re, im};
}

Complex::operator double() const {
    return sqrt((this->Re * this->Re) + (this->Im * this->Im));
}

// task 8

void FIFO::push(int value) {
    this->array[this->tail++] = value;
}

int FIFO::pop() {
    int tmp = this->array[0];
    for (int i = 1; i <= this->tail; ++i) {
        this->array[i - 1] = this->array[i];
    }
    --tail;
    return tmp;
}

void operator<<(FIFO &lhs, int value) {
    lhs.push(value);
}

void operator>>(FIFO &lhs, int &num) {
    num = lhs.pop();
}
