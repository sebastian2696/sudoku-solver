#include "main.h"

int main(void){
  int row;
  int num_runs;
  struct timeval start_time, end_time;

  // prompt for the file to read from?

  allocate_sudoku();
  populate_values();

  print_sudoku();

  num_runs = 0;

  gettimeofday(&start_time, NULL);

  while(get_num_unsolved(get_sudoku()) != 0){
    for(row = 0; row < 9; ++row){
      attempt_row_insertions(row);
    }
    ++num_runs;
  }

  gettimeofday(&end_time, NULL);

  printf("Time in microseconds: %ld\n", ((end_time.tv_sec - start_time.tv_sec)*1000000L +end_time.tv_usec) - start_time.tv_usec);

  printf("Num Runs: %d\n", num_runs);
  printf("\n");
  print_sudoku();

  free_sudoku();

  return 0;
}

void attempt_row_insertions(int row_num){
  int* row;
  struct array* missing_numbers;
  int i;
  int num;
  int col;
  int square_x;
  int square_y;
  int num_options;
  int option_col;

  square_x = row_num / 3;

  row = get_row(row_num);

  missing_numbers = calculateMissingNumbers(row);

  print_size9_array(row);
  print_array_struct(missing_numbers);

  for(i = 0; i < missing_numbers->size; ++i){
    num = missing_numbers->data[i];
    num_options = 0;
    option_col = 0;

    for(col = 0; col < 9; ++col){
      if(get_value(row_num, col) == 0){
        if(!contains_len9(get_col(col), num)){
          square_y = col / 3;

          if(!contains_square(get_square(square_x, square_y), num)){
            ++num_options;
            option_col = col;
          }
        }
      }
    }

    if(num_options == 1){
      set_val(row_num, option_col, num);
      printf("Change made\n");
      print_sudoku();
    }
  }

  free_1d_array(row);
  free_array_struct(missing_numbers);
}
