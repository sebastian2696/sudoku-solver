#include <stdio.h>
#include <stdlib.h>
#include "Main.h"

int main(){

  int** sudoku = setup_array();

  print_array(sudoku);
  set_values(sudoku);
  print_array(sudoku);

  return 0;
}

// allocates memory for the 2D array
int** setup_array(){

  int** array = (int**)malloc(sizeof(int*) * 9);

  for(int i = 0; i < 9; i++){
    array[i] = (int*)malloc(sizeof(int) * 9);
  }

  return array;
}

void print_array(int ** sudoku){
  for(int row = 0; row < 9; row++){
    for(int col = 0; col < 9; col++){
      printf("%d ", sudoku[row][col]);
    }
    printf("\n");
  }
  printf("\n");
}

// sets the values of the sudoku
// (most likely temporary until I get scanf working)
void set_values(int** sudoku){

  int row0[9] = {0,5,0,0,0,0,0,7,0};
  sudoku[0][0] = 0;
  sudoku[0][1] = 5;
  sudoku[0][2] = 0;
  sudoku[0][3] = 0;
  sudoku[0][4] = 0;
  sudoku[0][5] = 0;
  sudoku[0][6] = 0;
  sudoku[0][7] = 7;
  sudoku[0][8] = 0;

  int row1[9] = {0,0,0,3,0,2,0,0,0};
  sudoku[1][0] = 0;
  sudoku[1][1] = 0;
  sudoku[1][2] = 0;
  sudoku[1][3] = 3;
  sudoku[1][4] = 0;
  sudoku[1][5] = 2;
  sudoku[1][6] = 0;
  sudoku[1][7] = 0;
  sudoku[1][8] = 0;

  int row2[9] = {0,0,9,0,0,0,4,0,0};
  sudoku[2][0] = 0;
  sudoku[2][1] = 0;
  sudoku[2][2] = 9;
  sudoku[2][3] = 0;
  sudoku[2][4] = 0;
  sudoku[2][5] = 0;
  sudoku[2][6] = 4;
  sudoku[2][7] = 0;
  sudoku[2][8] = 0;

  int row3[9] = {3,0,0,0,9,0,0,0,2};
  sudoku[3][0] = 3;
  sudoku[3][1] = 0;
  sudoku[3][2] = 0;
  sudoku[3][3] = 0;
  sudoku[3][4] = 9;
  sudoku[3][5] = 0;
  sudoku[3][6] = 0;
  sudoku[3][7] = 0;
  sudoku[3][8] = 2;

  int row4[9] = {0,4,0,2,0,7,0,9,0};
  sudoku[4][0] = 0;
  sudoku[4][1] = 4;
  sudoku[4][2] = 0;
  sudoku[4][3] = 2;
  sudoku[4][4] = 0;
  sudoku[4][5] = 7;
  sudoku[4][6] = 0;
  sudoku[4][7] = 9;
  sudoku[4][8] = 0;

  int row5[9] = {0,9,0,6,8,4,0,5,0};
  sudoku[5][0] = 0;
  sudoku[5][1] = 9;
  sudoku[5][2] = 0;
  sudoku[5][3] = 6;
  sudoku[5][4] = 8;
  sudoku[5][5] = 4;
  sudoku[5][6] = 0;
  sudoku[5][7] = 5;
  sudoku[5][8] = 0;

  int row6[9] = {7,0,0,0,0,0,0,0,3};
  sudoku[6][0] = 7;
  sudoku[6][1] = 0;
  sudoku[6][2] = 0;
  sudoku[6][3] = 0;
  sudoku[6][4] = 0;
  sudoku[6][5] = 0;
  sudoku[6][6] = 0;
  sudoku[6][7] = 0;
  sudoku[6][8] = 3;

  int row7[9] = {0,1,2,0,0,0,9,6,0};
  sudoku[7][0] = 0;
  sudoku[7][1] = 1;
  sudoku[7][2] = 2;
  sudoku[7][3] = 0;
  sudoku[7][4] = 0;
  sudoku[7][5] = 0;
  sudoku[7][6] = 9;
  sudoku[7][7] = 6;
  sudoku[7][8] = 0;

  int row8[9] = {9,3,0,4,0,5,0,2,8};
  sudoku[8][0] = 9;
  sudoku[8][1] = 3;
  sudoku[8][2] = 0;
  sudoku[8][3] = 4;
  sudoku[8][4] = 0;
  sudoku[8][5] = 5;
  sudoku[8][6] = 0;
  sudoku[8][7] = 2;
  sudoku[8][8] = 8;

}
