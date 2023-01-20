#ifndef MATRIX_CALCULATOR_INVERSE_H
#define MATRIX_CALCULATOR_INVERSE_H


#include "INPUT.h"

class INVERSE : public INPUT {
public:
    INVERSE();

    void execute() override;

    void show() const override;

    void show_identity_matrix() const;

    void initialize_identity_matrix();

private:
    vector<vector<double>> matrix;
    vector<vector<double>> identity_matrix;
};


#endif //MATRIX_CALCULATOR_INVERSE_H