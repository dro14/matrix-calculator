#include "REF.h"


REF::REF() : matrix(::matrix) {}

void REF::execute() {

    vector<vector<double>> &A = matrix;
    unsigned long long nr = get_num_of_rows();
    unsigned long long nc = get_num_of_columns();

    cout << endl << endl << "Original matrix:" << endl;
    REF::show();
    cout << endl << endl;

//  Putting zero rows at the bottom
    check_again_1:
    for (int r = 0; r < nr; r++) {

//      Checking whether the current row is a zero row or not
        bool allZeros = true;
        for (int c = 0; c < nc; c++) {
            if (A[r][c] != 0) {
                allZeros = false;
                break;
            }
        }

//      If the current row is a zero row, then swap it with the last row
        if (allZeros && r != nr - 1) {
            for (int i = 0; i < nc; i++) {
                double temp_a = A[r][i];
                A[r][i] = A[nr - 1][i];
                A[nr - 1][i] = temp_a;
            }

            cout << "Swapping row " << nr << " with row " << r + 1 << ", which is a zero row" << endl;
            REF::show();
            cout << endl;

            nr--;
            goto check_again_1;
        }
    }

    int row = -1;
    for (int i = 0; i < nc; i++) {
        if (row + 1 < nr) row++;
        next_column:

//      Search for maximum in this column
        double maxEl = abs(A[row][i]);
        int maxRow = row;
        for (int r = row + 1; r < nr; r++) {
            if (maxEl < abs(A[r][i])) {
                maxEl = abs(A[r][i]);
                maxRow = r;
            }
        }

//      Swap maximum row with current row (column by column)
        if (row != maxRow && maxEl != 0) {
            for (int c = 0; c < nc; c++) {
                double temp_a = A[row][c];
                A[row][c] = A[maxRow][c];
                A[maxRow][c] = temp_a;
            }
            cout << "Swapping row " << row + 1 << " with row " << maxRow + 1 << ", which has the maximum absolute value of "
                 << maxEl << " in column " << i + 1 << endl;
            REF::show();
            cout << endl;
        } else if (maxEl == 0 && i + 1 < nc) {
            i++;
            goto next_column;
        }

//      Make all rows below the current row 0 in current column
        for (int k = row + 1; k < nr; k++) {
            double g = A[k][i] / A[row][i];
            if (g != 0 && A[row][i] != 0) {
                for (int j = 0; j < nc; j++) {
                    A[k][j] -= g * A[row][j];
                    if (abs(A[k][j]) < 1e-10 || A[k][j] == -0) A[k][j] = 0;
                }
                cout << "Subtracting row " << row + 1 << " multiplied by " << g << " from row " << k + 1 << endl;
                REF::show();
                cout << endl;
            }
        }
    }

//  Putting zero rows at the bottom
    check_again_2:
    for (int r = 0; r < nr; r++) {

//      Checking whether the current row is a zero row or not
        bool allZeros = true;
        for (int c = 0; c < nc; c++) {
            if (A[r][c] != 0) {
                allZeros = false;
                break;
            }
        }

//      If the current row is a zero row, then swap it with the last row
        if (allZeros && r != nr - 1) {
            for (int i = 0; i < nc; i++) {
                double temp_a = A[r][i];
                A[r][i] = A[nr - 1][i];
                A[nr - 1][i] = temp_a;
            }

            cout << "Swapping row " << nr << " with row " << r + 1 << ", which is a zero row" << endl;
            REF::show();
            cout << endl;

            nr--;
            goto check_again_2;
        }
    }

    cout << endl << "The matrix in Row Echelon Form:" << endl;
    REF::show();
    cout << endl << endl;
}

void REF::show() const {

    for (int i = 0; i < get_num_of_rows(); i++) {
        for (int j = 0; j < num_of_values[i]; j++) {
            cout << setw(12) << matrix[i][j];
        }
        cout << endl;
    }
}