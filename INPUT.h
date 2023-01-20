#ifndef MATRIX_CALCULATOR_INPUT_H
#define MATRIX_CALCULATOR_INPUT_H


#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;

extern vector<vector<double>> matrix;
extern vector<int> num_of_values;

class INPUT {
public:
    virtual void execute() = 0;

    virtual void show() const = 0;

    static void initialize_matrix();

    static void show_original_matrix();

    static void set_a_value_of_the_matrix();

    void set_num_of_rows(unsigned long long &);

    unsigned long long get_num_of_rows() const;

    void set_num_of_columns(unsigned long long &);

    unsigned long long get_num_of_columns() const;

private:
    unsigned long long num_of_rows = ::matrix.size();
    unsigned long long num_of_columns = ::matrix[0].size();
};


#endif //MATRIX_CALCULATOR_INPUT_H