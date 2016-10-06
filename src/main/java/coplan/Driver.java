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

        // reads from that file into a sudoku object
        Sudoku sudoku = SudokuFileReader.readFile(filepath);

        System.out.println(sudoku.getPercentSolved() + "\n");

        /*
         *  Main computational logic for solving of sudokus needs to either go here,
         *  or in a "Solver.java" class of sorts, which contains all of the loops and method
         *  calls necessary to find the solution.
         */

        sudoku.print();

        sudoku.printSquare(1,0);
        Output.printArray(Computations.calculateMissingNumbers(sudoku.getSquare(1,0)));


        LogicSolver solver = new LogicSolver();
        solver.tryRowFits(sudoku, 1);

    }
}

