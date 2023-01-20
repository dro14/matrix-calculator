#include "RANK.h"
#include "DETERMINANT.h"
#include "INVERSE.h"


vector<vector<double>> matrix;
vector<int> num_of_values;

int main() {

    cout << "\n\n\n                           Welcome to the MATRIX CALCULATOR!                               "
         << "\n                 The CALCULATOR is really glad to see You here!!! :)                           "
         << "\n\n\nSTEP 1: INPUTTING THE MATRIX";

    INPUT::initialize_matrix();

    static INPUT *ptr;
    REF obj1;
    RREF obj2;
    RANK obj3;
    DETERMINANT obj4;
    INVERSE obj5;

    perform_again:

    cout << "\nSTEP 2: CHOOSING A FUNCTION TO PERFORM ON THE MATRIX"
         << "\n\nTo use a function of the MATRIX CALCULATOR, enter one of the following numbers:"
         << "\n\nEnter 1 to transform the matrix into Row Echelon Form"
         << "\nEnter 2 to transform the matrix into Reduced-Row Echelon Form"
         << "\nEnter 3 to compute the rank of the matrix"
         << "\nEnter 4 to compute the determinant of the matrix"
         << "\nEnter 5 to computing the inverse of the matrix"
         << "\n\nTo enter a number: first press the number, and then press 'Enter'\n\n";

    int number = 0;
    cin >> number;

    switch (number) {
        case 1: {
            ptr = &obj1;
            break;
        }
        case 2: {
            ptr = &obj2;
            break;
        }
        case 3: {
            ptr = &obj3;
            break;
        }
        case 4: {
            ptr = &obj4;
            break;
        }
        case 5: {
            ptr = &obj5;
            break;
        }
        default: {
            cout << "\n\nInput is invalid. Enter one of the numbers mentioned\n\n";
            goto perform_again;
        }
    }

    ptr->execute();

    cout << "Enter 1 to perform another operation on this matrix"
         << "\nEnter anything else to quit the MATRIX CALCULATOR\n\n";

    short again;
    cin >> again;
    if (again == 1) goto perform_again;

    return 0;
}