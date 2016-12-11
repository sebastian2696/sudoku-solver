#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "computations.h"
#include "output.h"


int main(void){
  int** sudoku;

  sudoku = allocate_sudoku();

  populate_values(sudoku);

  print_sudoku(sudoku);


  return 0;
}

// allocates memory for the 2D array
int** allocate_sudoku(void){
  int** array;

  array = (int**)malloc(sizeof(int*) * 9);

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
