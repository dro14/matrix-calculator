#include "RREF.h"


void RREF::execute() {

    REF::execute();

    vector<vector<double>> &arr = matrix;
    unsigned long long r = get_num_of_rows();
    unsigned long long c = get_num_of_columns();

//  Making leading variables equal to 1
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] != 0) {
                double g = arr[i][j];
                for (int l = c - 1; l > -1; l--) {
                    if (arr[i][l] != 0) arr[i][l] /= g;
                    j++;
                }
                if(g != 1) {
                    cout << "Dividing row " << i + 1 << " by " << g << endl;
                    REF::show();
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
                        REF::show();
                        cout << endl;
                    }
                }
            }
            i++;
        }
    }

    cout << endl << "The matrix in Reduced-Row Echelon Form:" << endl;
    REF::show();
    cout << endl << endl;
}