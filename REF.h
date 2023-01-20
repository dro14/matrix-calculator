#ifndef MATRIX_CALCULATOR_REF_H
#define MATRIX_CALCULATOR_REF_H


#include "INPUT.h"

class REF : public INPUT {
public:
    REF();

    void execute() override;

    void show() const override;

protected:
    vector<vector<double>> matrix;
};


#endif //MATRIX_CALCULATOR_REF_H