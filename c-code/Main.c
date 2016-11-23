#include <stdlib.h>
#include <stdio.h>
#include "Main.h"
#include "Computations.h"
#include "Output.h"


int main(){

  int** sudoku = setup_array();
  logn("Sudoku allocated successfully.");

  set_values(sudoku);
  logn("Sudoku values filled.");

  logn("Initial, unsolved sudoku values:");
  print_sudoku(sudoku);

  print_row(sudoku, 0);
  print_col(sudoku, 0);
  print_square(sudoku, 1, 1);

  logn("Number unsolved:");
  printf("%d\n", get_num_unsolved(sudoku));

  logn("Percent unsolved:");
  printf("%f\n", get_percent_unsolved(sudoku));


  return 0;
}

// allocates memory for the 2D array
int** setup_array(){

  int** array = (int**)malloc(sizeof(int*) * 9);

  for(int i = 0; i < 9; ++i){
    array[i] = (int*)malloc(sizeof(int) * 9);
  }

  return array;
}

// sets the values of the sudoku
// (most likely temporary until I get scanf working)
void set_values(int** sudoku){

  sudoku[0][0] = 0;
  sudoku[0][1] = 8;
  sudoku[0][2] = 0;
  sudoku[0][3] = 0;
  sudoku[0][4] = 0;
  sudoku[0][5] = 4;
  sudoku[0][6] = 5;
  sudoku[0][7] = 0;
  sudoku[0][8] = 0;

  sudoku[1][0] = 0;
  sudoku[1][1] = 0;
  sudoku[1][2] = 0;
  sudoku[1][3] = 7;
  sudoku[1][4] = 9;
  sudoku[1][5] = 0;
  sudoku[1][6] = 6;
  sudoku[1][7] = 0;
  sudoku[1][8] = 2;

  sudoku[2][0] = 1;
  sudoku[2][1] = 0;
  sudoku[2][2] = 0;
  sudoku[2][3] = 2;
  sudoku[2][4] = 0;
  sudoku[2][5] = 5;
  sudoku[2][6] = 4;
  sudoku[2][7] = 7;
  sudoku[2][8] = 0;

  sudoku[3][0] = 7;
  sudoku[3][1] = 0;
  sudoku[3][2] = 4;
  sudoku[3][3] = 5;
  sudoku[3][4] = 0;
  sudoku[3][5] = 3;
  sudoku[3][6] = 0;
  sudoku[3][7] = 0;
  sudoku[3][8] = 0;

  sudoku[4][0] = 0;
  sudoku[4][1] = 0;
  sudoku[4][2] = 0;
  sudoku[4][3] = 0;
  sudoku[4][4] = 0;
  sudoku[4][5] = 0;
  sudoku[4][6] = 0;
  sudoku[4][7] = 0;
  sudoku[4][8] = 0;

  sudoku[5][0] = 0;
  sudoku[5][1] = 0;
  sudoku[5][2] = 0;
  sudoku[5][3] = 9;
  sudoku[5][4] = 0;
  sudoku[5][5] = 7;
  sudoku[5][6] = 3;
  sudoku[5][7] = 0;
  sudoku[5][8] = 4;

  sudoku[6][0] = 0;
  sudoku[6][1] = 7;
  sudoku[6][2] = 2;
  sudoku[6][3] = 4;
  sudoku[6][4] = 0;
  sudoku[6][5] = 9;
  sudoku[6][6] = 0;
  sudoku[6][7] = 0;
  sudoku[6][8] = 3;

  sudoku[7][0] = 4;
  sudoku[7][1] = 0;
  sudoku[7][2] = 1;
  sudoku[7][3] = 0;
  sudoku[7][4] = 8;
  sudoku[7][5] = 2;
  sudoku[7][6] = 0;
  sudoku[7][7] = 0;
  sudoku[7][8] = 0;

  sudoku[8][0] = 0;
  sudoku[8][1] = 0;
  sudoku[8][2] = 9;
  sudoku[8][3] = 1;
  sudoku[8][4] = 0;
  sudoku[8][5] = 0;
  sudoku[8][6] = 0;
  sudoku[8][7] = 4;
  sudoku[8][8] = 0;

}
