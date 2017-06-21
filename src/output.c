/*
MIT License

Copyright (c) 2017 Aaron Coplan

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <stdio.h>

#include "structs.h"
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
