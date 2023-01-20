#include "DETERMINANT.h"


DETERMINANT::DETERMINANT() : matrix(::matrix) {}

void DETERMINANT::execute() {

    vector<vector<double>> &A = matrix;
    unsigned long long nr = get_num_of_rows();
    unsigned long long nc = get_num_of_columns();
    double determinant = 1;
    int row;

    if (nr != nc)
        goto end;

    cout << endl << endl << "Original matrix:" << endl;
    DETERMINANT::show();
    cout << endl << endl;

//  Make all rows below the current row 0 in current column
    row = -1;
    for (int i = 0; i < nc; i++) {
        if (row + 1 < nr) row++;
        for (int k = row + 1; k < nr; k++) {
            double g = A[k][i] / A[row][i];
            if (g != 0 && A[row][i] != 0) {
                for (int j = 0; j < nc; j++) {
                    A[k][j] -= g * A[row][j];
                    if (abs(A[k][j]) < 1e-10 || A[k][j] == -0) A[k][j] = 0;
                }
                cout << "Subtracting row " << row + 1 << " multiplied by " << g << " from row " << k + 1 << endl;
                DETERMINANT::show();
                cout << endl;
            }
        }
    }

    cout << endl << "The matrix in Row Echelon Form:" << endl;
    DETERMINANT::show();
    cout << endl << endl;

//  Computing the matrix's determinant
    for (int i = 0; i < get_num_of_rows(); i++) {
        determinant *= matrix[i][i];
    }
    if(determinant == -0) determinant = 0;

    cout << "A matrix in Row Echelon form is also an upper triangular matrix."
         << "\nSo the product of the diagonal elements is equal to its determinant."
         << "\n\nThe matrix's determinant is " << determinant << endl << endl << endl;

    end:
    if (nr != nc)
        cout
                << "\n\nThe matrix does not have a determinant because the number of rows is not equal to the number of columns."
                << "\nIn other words, the matrix is not a square matrix, and only square matrices have determinants."
                << "\nRelaunch the CALCULATOR and enter a square matrix.\n\n";
}

void DETERMINANT::show() const {

    for (int i = 0; i < get_num_of_rows(); i++) {
        for (int j = 0; j < num_of_values[i]; j++) {
            cout << setw(12) << matrix[i][j];
        }
        cout << endl;
    }
}