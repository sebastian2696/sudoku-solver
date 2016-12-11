#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "computations.h"
#include "output.h"


int main(void){

  int** sudoku = allocate_sudoku();
  logn("Sudoku allocated successfully.");

  populate_values(sudoku);
  logn("Sudoku values filled.");

  logn("Initial, unsolved sudoku values:");
  print_sudoku(sudoku);

  /* print_row(sudoku, 0); */
  /* print_col(sudoku, 0); */
  /* print_square(sudoku, 1, 1); */

  /* logn("Number unsolved:"); */
  /* printf("%d\n", get_num_unsolved(sudoku)); */

  /* logn("Percent unsolved:"); */
  /* printf("%f\n", get_percent_unsolved(sudoku)); */

  /* int* row = get_row(sudoku, 1); */
  /* print_size9_array(row); */
  /* printf("%d\n", contains(calculateMissingNumbers(row), 7)); */

  return 0;
}

// allocates memory for the 2D array
int** allocate_sudoku(void){

  int** array = (int**)malloc(sizeof(int*) * 9);

  for(int i = 0; i < 9; ++i){
    array[i] = (int*)malloc(sizeof(int) * 9);
  }

  return array;
}

void populate_values(int** sudoku){
  // read from file and populate
  FILE* fptr;
  int run;
  int n;
  int row;
  int col;

  fptr = fopen("input/sudoku.txt", "r");

  row = 0;
  col = 0;

  run = 1;
  while(run){
    if(fscanf(fptr, "%d ", &n) != EOF){
      sudoku[row][col] = n;

      ++col;
      if(col == 9){
        col = 0;
        ++row;
      }

    }else{
      run = 0;
    }
  }

  fclose(fptr);
}
