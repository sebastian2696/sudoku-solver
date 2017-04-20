#include <stdlib.h>

#include "output.h"
#include "computations.h"

int default_numbers[9] = {1,2,3,4,5,6,7,8,9};

int get_num_unsolved(int** sudoku){

        int num_unsolved;
        int row;
        int col;

        num_unsolved = 0;

        for(row = 0; row < 9; ++row){
                for(col = 0; col < 9; ++col){
                        if(sudoku[row][col] == 0){
                                ++num_unsolved;
                        }
                }
        }

        return num_unsolved;
}

void free_array_struct(struct array* array){
        if(array){
                if(array->data){
                        free(array->data);
                }
                free(array);
        }
}


void free_2d_array(int** data){
        int i;

        if(data){
                for(i = 0; i < 3; ++i){
                        if(data[i]){
                                free(data[i]);
                        }
                }

                free(data);
        }

}

void free_1d_array(int* data){
        if(data){
                free(data);
        }
}

double get_percent_unsolved(int** sudoku){
        return (double)get_num_unsolved(sudoku) / 81.0;
}

int contains_square(int** square, int num){
        int row;
        int col;

        for(row = 0; row < 3; ++row){
                for(col = 0; col < 3; ++col){
                        if(square[row][col] == num){
                                return 1;
                        }
                }
        }

        return 0;
}


struct array* calculateSquareMissingNumbers(int** data){
        int* occurrences;
        int i;
        int row;
        int col;
        int occurrences_of_zero;
        int* missing_numbers;
        struct array* missing_numbers_array;
        int index;

        occurrences = (int*)malloc(sizeof(int) * 9);

        for(i = 0; i < 9; ++i){
                occurrences[i] = 0;
        }

        for(row = 0; row < 3; ++row){
                for(col = 0; col < 3; ++col){
                        if(data[row][col] != 0){
                                occurrences[data[row][col] - 1]++;
                        }
                }
        }

        occurrences_of_zero = 0;
        for(i = 0; i < 9; ++i){
                if(occurrences[i] == 0){
                        ++occurrences_of_zero;
                }
        }

        missing_numbers = (int*)malloc(sizeof(int) * occurrences_of_zero);
        missing_numbers_array = (struct array*)malloc(sizeof(struct array));

        index = 0;

        for(i = 0; i < 9; ++i){
                if(occurrences[i] == 0){
                        missing_numbers[index] = i + 1;
                        ++index;
                }
        }

        free(occurrences);

        missing_numbers_array->data = missing_numbers;
        missing_numbers_array->size = index;

        return missing_numbers_array;
}

struct array* calculateMissingNumbers(int* data){
        int* occurrences;
        int i;
        int occurrences_of_zero;
        int* missing_numbers;
        struct array* missing_numbers_array;
        int index;

        occurrences = (int*)malloc(sizeof(int) * 9);

        for(i = 0; i < 9; ++i){
                occurrences[i] = 0;
        }

        for(i = 0; i < 9; ++i){
                if(data[i] != 0){
                        occurrences[data[i] - 1]++;
                }
        }

        occurrences_of_zero = 0;
        for(i = 0; i < 9; ++i){
                if(occurrences[i] == 0){
                        ++occurrences_of_zero;
                }
        }

        missing_numbers = (int*)malloc(sizeof(int) * occurrences_of_zero);
        missing_numbers_array = (struct array*)malloc(sizeof(struct array));

        index = 0;

        for(i = 0; i < 9; ++i){
                if(occurrences[i] == 0){
                        missing_numbers[index] = i + 1;
                        ++index;
                }
        }

        free(occurrences);

        missing_numbers_array->data = missing_numbers;
        missing_numbers_array->size = index;

        return missing_numbers_array;
}

int contains_len9(int* data, int num){
        int i;

        for(i = 0; i < 9; ++i){
                if(data[i] == num){
                        return 1;
                }
        }
        return 0;
}

int contains(struct array* data, int num){
        int* arraydata;
        int i;

        arraydata = data->data;
        for(i = 0; i < data->size; ++i){
                if(arraydata[i] == num){
                        return 1;
                }
        }
        return 0;
}
