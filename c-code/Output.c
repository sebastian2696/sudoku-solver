#include <stdio.h>

void logn(char* log_string){
  printf("%s\n", log_string);
}

void print_sudoku(int ** sudoku){
  for(int row = 0; row < 9; ++row){
    for(int col = 0; col < 9; ++col){
      printf("%d ", sudoku[row][col]);
    }
    logn("");
  }
  logn("");
}

void print_row(int** sudoku, int row_number){
  int* row = sudoku[row_number];

  for(int i = 0; i < 9; ++i){
    printf("%d ", *row);
    row++;
  }

  logn("\n");
}

void print_col(int** sudoku, int col_number){

  for(int row = 0; row < 9; ++row){
    printf("%d\n", sudoku[row][col_number]);
  }

  logn("");
}

void print_square(int** sudoku, int square_x, int square_y){
  for(int row = (square_x * 3); row < square_x + 3; ++row){
    for(int col = (square_y * 3); col < square_y + 3; ++col){
      printf("%d ", sudoku[row][col]);
    }
    logn("");
  }
  logn("");
}
