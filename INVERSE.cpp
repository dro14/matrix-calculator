#include "INVERSE.h"


INVERSE::INVERSE() : matrix(::matrix) { INVERSE::initialize_identity_matrix(); }

void INVERSE::execute() {

    vector<vector<double>> &A = matrix;
    vector<vector<double>> &arr = matrix;
    vector<vector<double>> &I = identity_matrix;
    unsigned long long nr = get_num_of_rows();
    unsigned long long r = get_num_of_rows();
    unsigned long long nc = get_num_of_columns();
    unsigned long long c = get_num_of_columns();

    cout << endl << endl << "Original matrix:" << endl;
    INVERSE::show();
    cout << "Identity matrix:" << endl;
    INVERSE::show_identity_matrix();
    cout << endl;

//  Make all rows below this one 0 in current column
    int row = -1;
    for (int i = 0; i < nc; i++) {
        if (row + 1 < nr) row++;
        for (int k = row + 1; k < nr; k++) {
            double g = A[k][i] / A[row][i];
            if (g != 0 && A[row][i] != 0) {
                for (int j = 0; j < nc; j++) {
                    A[k][j] -= g * A[row][j];
                    I[k][j] -= g * I[row][j];
                    if (abs(A[k][j]) < 1e-10 || A[k][j] == -0) A[k][j] = 0;
                    if (abs(I[k][j]) < 1e-10 || I[k][j] == -0) I[k][j] = 0;
                }
                cout << "Subtracting row " << row + 1 << " multiplied by " << g << " from row " << k + 1 << endl;
                INVERSE::show();
                cout << "----------------------------------------" << endl;
                INVERSE::show_identity_matrix();
                cout << endl;
            }
        }
    }

//  Making leading variables equal to 1
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] != 0) {
                double g = arr[i][j];
                for (int l = c - 1; l > -1; l--) {
                    if (arr[i][l] != 0) arr[i][l] /= g;
                    if (I[i][l] != 0) I[i][l] /= g;
                    j++;
                }
                if (g != 1) {
                    cout << "Dividing row " << i + 1 << " by " << g << endl;
                    INVERSE::show();
                    cout << "----------------------------------------" << endl;
                    INVERSE::show_identity_matrix();
                    cout << endl;
                }
            }
        }
    }

//  Make all rows above this one 0
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == 1) {
                for (int k = i - 1; k > -1; k--) {
                    double g = arr[k][j];
                    if (g != 0) {
                        for (int l = 0; l < c; l++) {
                            arr[k][l] -= g * arr[i][l];
                        }
                        cout << "Subtracting row " << i + 1 << " multiplied by " << g << " from row " << k + 1 << endl;
                        INVERSE::show();
                        cout << "----------------------------------------" << endl;
                        INVERSE::show_identity_matrix();
                        cout << endl;
                    }
                }
            }
            i++;
        }
    }

    bool is_it_identity = true;
    for (int i = 0; i < get_num_of_rows(); i++) {
        for (int j = 0; j < get_num_of_columns(); j++) {
            if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0)) {
                is_it_identity = false;
                break;
            }
        }
    }

    if (is_it_identity) {
        cout << "Identity matrix:" << endl;
        INVERSE::show();
        cout << "Inverse matrix:" << endl;
        INVERSE::show_identity_matrix();
        cout << endl << endl;
    } else {
        cout << "\nThe matrix is not invertible because its Reduced-Row Echelon Form is not the identity matrix."
             << "\nThe matrix in Reduced-Row Echelon Form:" << endl;
        INVERSE::show();
        cout << endl << endl;
    }
}

void INVERSE::show() const {

    for (int i = 0; i < get_num_of_rows(); i++) {
        for (int j = 0; j < num_of_values[i]; j++) {
            cout << setw(12) << matrix[i][j];
        }
        cout << endl;
    }
}

void INVERSE::show_identity_matrix() const {

    for (int i = 0; i < get_num_of_rows(); i++) {
        for (int j = 0; j < num_of_values[i]; j++) {
            cout << setw(12) << identity_matrix[i][j];
        }
        cout << endl;
    }
}

void INVERSE::initialize_identity_matrix() {

    if (get_num_of_rows() == get_num_of_columns()) {
        identity_matrix = ::matrix;
        for (int i = 0; i < get_num_of_rows(); i++) {
            for (int j = 0; j < num_of_values[i]; j++) {
                if (i == j) identity_matrix[i][j] = 1;
                else identity_matrix[i][j] = 0;
            }
        }
    } else {
        cout << "\n\nThe matrix is not invertible and does not have a determinant because the number of rows"
             << "\nis not equal to the number of columns. In other words, the matrix is not a square matrix."
             << "\nTo use functions 4 and 5, relaunch the MATRIX CALCULATOR and enter a square matrix.\n\n";
    }
}