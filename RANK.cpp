#include "RANK.h"


void RANK::execute() {

    RREF::execute();

    int rank = 0;

    for (int i = 0; i < get_num_of_rows(); i++) {
        for (int j = 0; j < num_of_values[i]; j++) {
            if (matrix[i][j] == 1) {
                rank++;
                if (i + 1 < get_num_of_rows()) i++;
            }
        }
    }

    cout << "The matrix's rank is " << rank << endl << endl << endl;
}