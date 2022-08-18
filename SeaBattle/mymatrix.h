#ifndef MYMATRIX_H
#define MYMATRIX_H
#include <QVector>

class MyMatrix
{
   public:

        MyMatrix(int rows, int cols, double initValues=0.0);   // constructor
        QVector<double> operator[](int idx);
        double const& operator()(size_t rowIndex, size_t colIndex) const;
        double& operator()(size_t rowIndex, size_t colIndex);

   private:
        QVector<QVector<double>> *mat;
};

#endif // MYMATRIX_H
