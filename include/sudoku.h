#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdlib.h>
#include <stdio.h>

void allocate_sudoku(void);
void populate_values(void);
void free_sudoku(void);
int* get_row(int** sudoku, int row_number);
int* get_col(int** sudoku, int col_number);
int** get_square(int** sudoku, int square_x, int square_y);
int** get_sudoku(void);
void print_sudoku(void);

#endif
