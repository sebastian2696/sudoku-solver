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

#include <stdlib.h>
#include <stdio.h>

#include "sudoku.h"
#include "output.h"

int** sudoku;

void allocate_sudoku(void){
        int i;

        sudoku = (int**)malloc(sizeof(int*) * 9);

        for(i = 0; i < 9; ++i){
                sudoku[i] = (int*)malloc(sizeof(int) * 9);
        }
}

void populate_values(char* file_path){
        // read from file and populate
        FILE* fptr;
        int run;
        int n;
        int row;
        int col;

        fptr = fopen(file_path, "r");

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

int* get_row(int row_number){
        int* row;
        int col;

        row = (int*)malloc(sizeof(int) * 9);

        for(col = 0; col < 9; ++col){
                row[col] = sudoku[row_number][col];
        }

        return row;
}

int* get_col(int col_number){
        int* col;
        int row;

        col = (int*)malloc(sizeof(int) * 9);

        for(row = 0; row < 9; ++row){
                col[row] = sudoku[row][col_number];
        }

        return col;
}

int get_value(int row, int col){
        return sudoku[row][col];
}

int** get_square(int square_x, int square_y){

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

void set_val(int row, int col, int num){
        sudoku[row][col] = num;
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

int validate_sudoku(void){
        int i;
        int row_num;
        int col_num;
        int* row;
        int* col;
        int** square;

        for(i = 0; i < 9; ++i){
                row = get_row(i);
                col = get_col(i);

                if(validate_row(row) == -1){
                        printf("Invalid row: %d\n", i);
                        print_size9_array(row);
                        return -1;
                }

                if(validate_col(col) == -1){
                        printf("Invalid col: %d\n", i);
                        print_size9_array(col);
                        return -1;
                }
        }

        for(row_num = 0; row_num < 3; ++row_num){
                for(col_num = 0; col_num < 3; ++col_num){
                        square = get_square(row_num, col_num);

                        if(validate_square(square) == -1){
                                printf("Invalid square: %d, %d\n", row_num, col_num);
                                print_3x3_array(square);
                                return -1;
                        }
                }
        }

        return 0;
}

int validate_row(int* row){
        int i;
        int j;
        int num;

        for(i = 0; i < 9; ++i){
                num = row[i];
                if(num == 0){
                        continue;
                }

                for(j = i + 1; j < 9; ++j){
                        if(row[j] == num){
                                return -1;
                        }
                }
        }

        return 0;
}

int validate_col(int* col){
        int i;
        int j;
        int num;

        for(i = 0; i < 9; ++i){
                num = col[i];
                if(num == 0){
                        continue;
                }

                for(j = i + 1; j < 9; ++j){
                        if(col[j] == num){
                                return -1;
                        }
                }
        }

        return 0;
}

int validate_square(int** square){
        int num;
        int row;
        int col;
        int r2;
        int c2;

        for(row = 0; row < 3; ++row){
                for(col = 0; col < 3; ++col){
                        num = square[row][col];
                        if(num == 0){
                                continue;
                        }

                        for(r2 = 0; r2 < 3; ++r2){
                                for(c2 = 0; c2 < 3; ++c2){
                                        if(row == r2 && col == c2){
                                                continue;
                                        }

                                        if(num == square[r2][c2]){
                                                return -1;
                                        }
                                }
                        }
                }
        }

        return 0;
}
