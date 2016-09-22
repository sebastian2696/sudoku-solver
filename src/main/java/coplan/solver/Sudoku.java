package coplan.solver;

import coplan.io.Output;

/**
 * Created by afcoplan on 9/20/16.
 */
public class Sudoku {

    private int[][] data;
    private final int width, height, num_boxes;

    public Sudoku(int[][] data){
        this.width = 9;
        this.height = 9;
        this.num_boxes = width * height;

        if(data.length != width || data[0].length != height){
            System.out.println("Sudoku data given is of the wrong dimensions! Exiting now.");
            System.exit(-1);
        }

        this.data = data;
    }

    public int getUnsolvedRemaining(){
        int num_unsolved = 0;

        for(int row = 0; row < height; row++){
            for(int col = 0; col < width; col++){
                if(data[row][col] ==  0){
                    num_unsolved++;
                }
            }
        }

        return num_unsolved;
    }

    public double getPercentSolved(){
        return 100 * (1 - (((double)getUnsolvedRemaining()) / num_boxes));
    }

    public int[] getRow(int index){
        return data[index];
    }

    public int[] getCol(int index){
        int[] column = new int[height];

        for(int row = 0; row < height; row++){
            column[row] = data[row][index];
        }

        return column;
    }

    public int[][] getSquare(int verticalIndex, int horizontalIndex){
        int startY = verticalIndex * 3;
        int startX = horizontalIndex * 3;

        int[][] square = new int[3][3];

        int squareX = 0;
        int squareY = 0;

        for(int y = startY; y < (startY + 3); y++){
            for(int x = startX; x < (startX + 3); x++){
                square[squareY][squareX] = data[y][x];
                squareX++;
            }
            squareY++;
            squareX = 0;
        }

        return square;
    }

    public void print(){
        Output.printArray(data);
    }

    public void printRow(int index){
        Output.printArray(this.getRow(index));
    }

    public void printCol(int index){
        Output.printVerticalArray(this.getCol(index));
    }

    public void printSquare(int verticalIndex, int horizontalIndex){
        Output.printArray(this.getSquare(verticalIndex, horizontalIndex));
    }
}
