#ifndef INC_1_TASK_H
#define INC_1_TASK_H

void firstRef(double &, double);

void firstPtr(double *, double);

void secondRef(double &);

void secondPtr(double *);

struct complexNumber {
    double Re;
    double Im;
};

void thirdRef(complexNumber &number);

void thirdPtr(complexNumber *number);

struct matrix {
    double data[3][3];
};

void fourthRef(matrix &, double);

void fourthPtr(matrix *, double);

#endif //INC_1_TASK_H
