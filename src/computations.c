#include <stdlib.h>
#include "output.h"
#include "computations.h"

int default_numbers[9] = {1,2,3,4,5,6,7,8,9};

int get_num_unsolved(int** sudoku){

  int num_unsolved = 0;

  for(int row = 0; row < 9; ++row){
    for(int col = 0; col < 9; ++col){
      if(sudoku[row][col] == 0){
        ++num_unsolved;
      }
    }
  }

  return num_unsolved;
}

double get_percent_unsolved(int** sudoku){
  double num_unsolved = (double)get_num_unsolved(sudoku);

  return num_unsolved / 81.0;
}

int* get_row(int** sudoku, int row_number){
  int* row = sudoku[row_number];

  return row;
}

int* get_col(int** sudoku, int col_number){
  int* col = (int*)malloc(sizeof(int) * 9);

  for(int row = 0; row < 9; ++row){
    col[row] = sudoku[row][col_number];
  }

  return col;
}

int** get_square(int** sudoku, int square_x, int square_y){

  int** square = (int**)malloc(sizeof(int*) * 3);

  for(int i = 0; i < 3; ++i){
    square[i] = (int*)malloc(sizeof(int) * 3);
  }

  int square_row = 0;
  int square_col = 0;

  for(int row = (square_x * 3); row < ((square_x * 3) + 3); ++row){
    for(int col = (square_y * 3); col < ((square_y * 3) + 3); ++col){
      square[square_row][square_col] = sudoku[row][col];
      ++square_col;
    }
    square_col = 0;
    ++square_row;
  }

  return square;
}

struct array* calculateSquareMissingNumbers(int** data){
  int* occurrences = (int*)malloc(sizeof(int) * 9);

  for(int i = 0; i < 9; ++i){
    occurrences[i] = 0;
  }

  for(int row = 0; row < 3; ++row){
    for(int col = 0; col < 3; ++col){
      if(data[row][col] != 0){
        occurrences[data[row][col] - 1]++;
      }
    }
  }

  int occurrences_of_zero = 0;
  for(int i = 0; i < 9; ++i){
    if(occurrences[i] == 0){
      ++occurrences_of_zero;
    }
  }

  int* missing_numbers = (int*)malloc(sizeof(int) * occurrences_of_zero);
  struct array* missing_numbers_array = (struct array*)malloc(sizeof(struct array));

  int index = 0;

  for(int i = 0; i < 9; ++i){
    if(occurrences[i] == 0){
      missing_numbers[index] = i + 1;
      ++index;
    }
  }

  missing_numbers_array->data = missing_numbers;
  missing_numbers_array->size = index;

  return missing_numbers_array;
}

struct array* calculateMissingNumbers(int* data){
  int* occurrences = (int*)malloc(sizeof(int) * 9);

  for(int i = 0; i < 9; ++i){
    occurrences[i] = 0;
  }

  for(int i = 0; i < 9; ++i){
    if(data[i] != 0){
      occurrences[data[i] - 1]++;
    }
  }

  int occurrences_of_zero = 0;
  for(int i = 0; i < 9; ++i){
    if(occurrences[i] == 0){
      ++occurrences_of_zero;
    }
  }

  int* missing_numbers = (int*)malloc(sizeof(int) * occurrences_of_zero);
  struct array* missing_numbers_array = (struct array*)malloc(sizeof(struct array));

  int index = 0;

  for(int i = 0; i < 9; ++i){
    if(occurrences[i] == 0){
      missing_numbers[index] = i + 1;
      ++index;
    }
  }

  missing_numbers_array->data = missing_numbers;
  missing_numbers_array->size = index;

  return missing_numbers_array;
}

int contains_len9(int* data, int num){
  for(int i = 0; i < 9; ++i){
    if(data[i] == num){
      return 1;
    }
  }
  return 0;
}

int contains(struct array* data, int num){
  int* arraydata = data->data;
  for(int i = 0; i < data->size; ++i){
    if(arraydata[i] == num){
      return 1;
    }
  }
  return 0;
}
