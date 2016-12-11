#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdio.h>
#include "computations.h"
#include "structs.h"

void print_row(int** sudoku, int row_number);
void print_col(int** sudoku, int col_number);
void print_square(int** sudoku, int square_x, int square_y);
void print_size9_array(int* data);
void print_array_struct(struct array* array);
void print_3x3_array(int** data);

#endif
