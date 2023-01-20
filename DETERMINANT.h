#ifndef MATRIX_CALCULATOR_DETERMINANT_H
#define MATRIX_CALCULATOR_DETERMINANT_H


#include "INPUT.h"

class DETERMINANT : public INPUT {
public:
    DETERMINANT();

    void execute() override;

    void show() const override;

private:
    vector<vector<double>> matrix;
};


#endif //MATRIX_CALCULATOR_DETERMINANT_H