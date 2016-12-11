#include "sudoku.h"

int** sudoku;

void allocate_sudoku(void){
  int i;

  sudoku = (int**)malloc(sizeof(int*) * 9);

  for(i = 0; i < 9; ++i){
    sudoku[i] = (int*)malloc(sizeof(int) * 9);
  }
}

void populate_values(void){
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

void free_sudoku(void){
  int i;

  for(i = 0; i < 9; ++i){
    if(sudoku[i]){
      free(sudoku[i]);
    }
  }

  if(sudoku){
    free(sudoku);
  }
}

int** get_sudoku(void){
  return sudoku;
}

int* get_row(int** sudoku, int row_number){
  int* row;

  row = sudoku[row_number];

  return row;
}

int* get_col(int** sudoku, int col_number){
  int* col;
  int row;

  col = (int*)malloc(sizeof(int) * 9);

  for(row = 0; row < 9; ++row){
    col[row] = sudoku[row][col_number];
  }

  return col;
}

int** get_square(int** sudoku, int square_x, int square_y){

  int** square;
  int i;
  int square_row;
  int square_col;
  int row;
  int col;

  square = (int**)malloc(sizeof(int*) * 3);

  for(i = 0; i < 3; ++i){
    square[i] = (int*)malloc(sizeof(int) * 3);
  }

  square_row = 0;
  square_col = 0;

  for(row = (square_x * 3); row < ((square_x * 3) + 3); ++row){
    for(col = (square_y * 3); col < ((square_y * 3) + 3); ++col){
      square[square_row][square_col] = sudoku[row][col];
      ++square_col;
    }
    square_col = 0;
    ++square_row;
  }

  return square;
}


void print_sudoku(void){
  for(int row = 0; row < 9; ++row){
    for(int col = 0; col < 9; ++col){
      printf("%d ", sudoku[row][col]);
    }
    printf("\n");
  }
  printf("\n");
}
