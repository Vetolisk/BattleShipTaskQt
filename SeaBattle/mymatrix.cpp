#include "mymatrix.h"

// constructor
MyMatrix::MyMatrix(int rows, int cols, double initValues)
{

    QVector<double> tmpRow(cols, initValues);
    this->mat = new QVector<QVector<double>>(rows, tmpRow);
}

// operator definition
QVector<double> MyMatrix::operator[](int idx) {
    QVector<double> temp = this->mat[0][idx];
    return temp;
}
