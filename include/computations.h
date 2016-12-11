#ifndef COMPUTATIONS_H
#define COMPUTATIONS_H

struct array {
  int* data;
  int size;
};

int get_num_unsolved(int** sudoku);
double get_percent_unsolved(int** sudoku);
int* get_row(int** sudoku, int row_number);
int* get_col(int** sudoku, int col_number);
int** get_square(int** sudoku, int square_x, int square_y);
struct array* calculateMissingNumbers(int* data);
struct array* calculateSquareMissingNumbers(int** data);
int contains_len9(int* data, int num);
int contains(struct array* data, int num);

#endif
