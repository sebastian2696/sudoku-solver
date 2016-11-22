#include <stdio.h>
#include <stdlib.h>
#include "Main.h"

int main(){

  int** sudoku = setupArray();

  setValues(sudoku);


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

// sets the values of the sudoku
// (most likely temporary until I get scanf working)
void set_values(int** sudoku){

  int row0[9] = {050000070};
  int row1[9] = {000302000};
  int row2[9] = {009000400};
  int row3[9] = {300090002};
  int row4[9] = {040207090};
  int row5[9] = {090684050};
  int row6[9] = {700000003};
  int row7[9] = {012000960};
  int row8[9] = {930405028};

  sudoku[0] = row0;
  sudoku[1] = row1;
  sudoku[2] = row2;
  sudoku[3] = row3;
  sudoku[4] = row4;
  sudoku[5] = row5;
  sudoku[6] = row6;
  sudoku[7] = row7;
  sudoku[8] = row8;
}
