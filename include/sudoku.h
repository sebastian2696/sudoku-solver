#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdlib.h>
#include <stdio.h>

extern int** sudoku;

void allocate_sudoku(void);
void populate_values(void);
void free_sudoku(void);
int get_value(int row, int col);
int* get_row(int row_number);
int* get_col(int col_number);
int** get_square(int square_x, int square_y);
int** get_sudoku(void);
void set_val(int row, int col, int num);
void print_sudoku(void);

#endif
