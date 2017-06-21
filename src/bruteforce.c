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

#include "bruteforce.h"
//#include "sudoku.h"
#define RESET 0

int ** sudoku;

int row,col;
long int Calls = 0;

int findEmptyCell(void){
        int i,j;

        for(i = row ; i<=8; i++){
                for( j = 0; j<=8; j++){
                        if(sudoku[i][j] == 0){
                                row = i;
                                col = j;
                                return 1;
                        }
                }
        }
        return 0;
}

int isValid(int cRow, int cCol, int num){
        int i,j;
        //trow,tcol,trow1,tcol1;
        int rowStart = (cRow/3) * 3;
        int colStart = (cCol/3) * 3;

        //Check Row && Column

        for (j = 0; j<=8; j++){
                if(sudoku[cRow][j] == num)
                        return 0;
                if(sudoku[j][cCol] == num)
                        return 0;
        }

        //Ckeck 3x3

        for (i=rowStart; i<=(rowStart +2); i++){
                for (j=colStart; j<=(colStart +2); j++){
                        if (sudoku[i][j] == num) return 0;
                }
        }
        return 1;
}

int brute_force_solve(void){
        int digit;
        int pRow, pCol;
        Calls++;

        if(!findEmptyCell())
                return 1;

        for(digit=1; digit<=9; digit++){
                if(isValid(row,col,digit)){
                        sudoku[row][col]=digit;
                        pRow = row;
                        pCol = col;
                        if (brute_force_solve())
                                return 1;
                        //Backtracking
                        row = pRow; col = pCol;
                        sudoku[row][col] = RESET;
                }
        }

        return 0;

}
/*
  void printSudoku(){

  int i,j;

  printf("Calls:%ld\n",Calls);

  printf("\t-------------------------\n");
  for(i=0;i<9;i++){
  printf("\t");
  for(j=0;j<9;j++){
  if(j==0)
  printf("| ");
  if(sudoku[i][j]==0)
  printf(". ");
  else
  printf("%d ",sudoku[i][j]);
  if((j+1)%3==0 )
  printf("| ");

  }

  if((i+1)%3==0 )
  printf("\n\t-------------------------");

  printf("\n");

  }

  }*/
