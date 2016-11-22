package coplan;

import coplan.io.Output;
import coplan.io.SudokuFileReader;
import coplan.solver.Computations;
import coplan.solver.LogicSolver;
import coplan.solver.Sudoku;

/*
 * Main class. The main method is called when the jar is run.
 */
public class Driver {

    public static void main( String[] args ) {

        // filepath to the current sudoku you would like to use for testing purposes
        String filepath = "src/main/resources/sudokus/easy.sudoku";
        String filepath2 = "src/main/resources/sudokus/c-easy.sudoku";

        // reads from that file into a sudoku object
        Sudoku sudoku = SudokuFileReader.readFile(filepath);
        Sudoku sudoku1 = SudokuFileReader.readFile(filepath2);

        for(int row = 0; row < 9; ++row){
            int[] row1 = sudoku.getRow(row);
            int[] row2 = sudoku.getRow(row);

            for(int col = 0; col < 9; col++){
                if(row1[col] != row2[col]){
                    System.out.println("ERROR! DIFFERENCE");
                }
            }
        }

        System.out.println("Comparison done!");
    }
}

