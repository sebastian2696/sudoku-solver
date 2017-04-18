#include "output.h"


void print_row(int** sudoku, int row_number){
        int* row = sudoku[row_number];

        for(int i = 0; i < 9; ++i){
                printf("%d ", *row);
                row++;
        }

        printf("\n\n");
}

void print_col(int** sudoku, int col_number){

        for(int row = 0; row < 9; ++row){
                printf("%d\n", sudoku[row][col_number]);
        }

        printf("\n");
}

void print_square(int** sudoku, int square_x, int square_y){
        for(int row = (square_x * 3); row < ((square_x * 3) + 3); ++row){
                for(int col = (square_y * 3); col < ((square_y * 3) + 3); ++col){
                        printf("%d ", sudoku[row][col]);
                }
                printf("\n");
        }
        printf("\n");
}

void print_size9_array(int* data){
        for(int i = 0; i < 9; ++i){
                printf("%d ", data[i]);
        }
        printf("\n");
}

void print_3x3_array(int** data){
        for(int row = 0; row < 3; ++row){
                for(int col = 0; col < 3; ++col){
                        printf("%d ", data[row][col]);
                }
                printf("\n");
        }
        printf("\n");
}

void print_array_struct(struct array* array){
        int* arr = array->data;
        int size = array->size;

        for(int i = 0; i < size; ++i){
                printf("%d ", arr[i]);
        }
        printf("\n");
}
