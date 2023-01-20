#include "INPUT.h"


void INPUT::initialize_matrix() {

    int how_many = 0;
    double temp = 0.0;
    bool no_errors = true;
    string temp_str;
    vector<double> temp_vec;

    cout << "\n\nEach line is considered as a row. For a new row, create a new line by pressing 'Enter'."
         << "\nTo enter non-integer numbers, use \".\" (dot or point). Do not use \",\" (comma)."
         << "\nIf the value is zero, you should enter it. Do not skip it."
         << "\nTo complete entering, type \"end\" on a new line."
         << "\nEnter the values of the matrix separating them by a space:\n\n\n";

    getline(cin, temp_str);

    while (temp_str != "end") {

        stringstream ss_1(temp_str);
        while (ss_1 >> temp) {
            how_many++;
        }

        stringstream ss_2(temp_str);
        for (int i = 0; i < how_many; i++) {
            ss_2 >> temp;
            temp_vec.push_back(temp);
        }

        matrix.push_back(temp_vec);
        temp_vec.clear();
        num_of_values.push_back(how_many);
        how_many = 0;
        getline(cin, temp_str);
    }

    for (auto &i: matrix) {
        if (i.size() != matrix[0].size()) {
            cout << "\n\nThe number of values is not same in each row."
                 << "\nRelaunch the MATRIX CALCULATOR and try to enter the matrix properly.\n\n";
            INPUT::show_original_matrix();
            cout << endl << endl;
            no_errors = false;
            break;
        }
    }
    if (no_errors) {
        cout << "\n\nThe entered matrix is with " << matrix.size() << " row(s) and "
             << matrix[0].size() << " column(s):" << endl;
        INPUT::show_original_matrix();
        cout << endl << endl;
    }

    temp = 0.0;
    no_errors = true;
    temp_str.clear();
    temp_vec.clear();
}

void INPUT::show_original_matrix() {

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < num_of_values[i]; j++) {
            cout << setw(12) << matrix[i][j];
        }
        cout << endl;
    }
}

void INPUT::set_a_value_of_the_matrix() {

    int row_num;
    int column_num;
    double value;

    cout << "\nEnter the position of the cell whose value you want to change."
         << "\nEnter the row number:\n";
    cin >> row_num;
    cout << "\nEnter the column number:\n";
    cin >> column_num;
    cout << "\nEnter the value which you want to set:\n";
    cin >> value;

    if (row_num > 0 && row_num <= matrix.size()
        && column_num > 0 && column_num <= matrix[0].size()) {
        matrix[row_num - 1][column_num - 1] = value;
        cout << "\nThe matrix after the change:\n";
        INPUT::show_original_matrix();
        cout << endl << endl;
    } else
        cout << "Invalid position data is entered."
             << "\nRelaunch the MATRIX CALCULATOR and try to enter valid data.";

    row_num = 0;
    column_num = 0;
    value = 0.0;
}

void INPUT::set_num_of_rows(unsigned long long &rows) { num_of_rows = rows; }

unsigned long long INPUT::get_num_of_rows() const { return num_of_rows; }

void INPUT::set_num_of_columns(unsigned long long &columns) { num_of_columns = columns; }

unsigned long long INPUT::get_num_of_columns() const { return num_of_columns; }