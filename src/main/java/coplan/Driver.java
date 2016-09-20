package coplan;

import coplan.solver.Sudoku;

/**
 * Hello world!
 *
 */
public class Driver {

    public static void main( String[] args ) {

        int[][] sudoku_data = new int[9][9];
        sudoku_data[0][0] = 3;

        Sudoku sudoku = new Sudoku(sudoku_data);
        System.out.println(sudoku.getPercentSolved());
    }
}
