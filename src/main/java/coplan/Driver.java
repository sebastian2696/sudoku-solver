package coplan;

import coplan.io.Output;
import coplan.io.SudokuFileReader;
import coplan.solver.Computations;
import coplan.solver.LogicSolver;
import coplan.solver.Sudoku;

/**
 * Hello world!
 *
 */
public class Driver {

    public static void main( String[] args ) {

        String filepath = "/home/afcoplan/code/sudokus/easy.sudoku";

        Sudoku sudoku = SudokuFileReader.readFile(filepath);

        System.out.println(sudoku.getPercentSolved() + "\n");

        sudoku.print();

        sudoku.printSquare(1,0);
        Output.printArray(Computations.calculateMissingNumbers(sudoku.getSquare(1,0)));


        LogicSolver solver = new LogicSolver();
        solver.tryRowFits(sudoku, 1);

    }
}

