#ifndef COMPUTATIONS_H
#define COMPUTATIONS_H

#include "structs.h"

int get_num_unsolved(int** sudoku);
double get_percent_unsolved(int** sudoku);
struct array* calculateMissingNumbers(int* data);
struct array* calculateSquareMissingNumbers(int** data);
int contains_len9(int* data, int num);
int contains_square(int** square, int num);
int contains(struct array* data, int num);
void free_array_struct(struct array* array);
void free_1d_array(int* data);
void free_2d_array(int** data);

#endif
