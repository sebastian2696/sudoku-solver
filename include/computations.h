#ifndef COMPUTATIONS_H
#define COMPUTATIONS_H

#include <stdlib.h>
#include "output.h"
#include "structs.h"

int get_num_unsolved(int** sudoku);
double get_percent_unsolved(int** sudoku);
struct array* calculateMissingNumbers(int* data);
struct array* calculateSquareMissingNumbers(int** data);
int contains_len9(int* data, int num);
int contains(struct array* data, int num);

#endif
