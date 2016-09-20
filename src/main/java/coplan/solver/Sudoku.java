package coplan.solver;

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

        if(data.length != 0 || data[0].length != 0){
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
        return 1 - (((double)getUnsolvedRemaining()) / num_boxes);
    }
}
