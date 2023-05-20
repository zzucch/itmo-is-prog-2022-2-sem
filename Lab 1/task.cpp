#include "task.h"

// 2:   Increasing the value of one variable by a given amount (second variable)
void firstRef(double &value, double delta) {
    value += delta;
}

void firstPtr(double *value, double delta) {
    *value += delta;
}

// 7:   Changing sign of variable (real, integer)
void secondRef(double &number) {
    number *= -1;
}

void secondPtr(double *number) {
    *number *= -1;
}

// 10:  Finding complex conjugate (x+yi -> x-yi)
void thirdRef(complexNumber &number) {
    number.Im *= -1;
}

void thirdPtr(complexNumber *number) {
    number->Im *= -1;
}

// 15:  Multiplying a 3x3 matrix by a real number
void fourthRef(matrix &Matrix, double multiplicand) {
    int matrix_size = 3;

    for (int i = 0; i < matrix_size; ++i) {
        for (int j = 0; j < matrix_size; ++j) {
            Matrix.data[i][j] *= multiplicand;
        }
    }
}

void fourthPtr(matrix *pMatrix, double multiplicand) {
    int matrix_size = 3;

    for (int i = 0; i < matrix_size; ++i) {
        for (int j = 0; j < matrix_size; ++j) {
            pMatrix->data[i][j] *= multiplicand;
        }
    }
}

