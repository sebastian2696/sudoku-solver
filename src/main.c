#include "main.h"

int main(void){
  allocate_sudoku();
  populate_values();

  attempt_row_insertions(0);

  print_sudoku();

  free_sudoku();

  return 0;
}

void attempt_row_insertions(int row_num){

}
