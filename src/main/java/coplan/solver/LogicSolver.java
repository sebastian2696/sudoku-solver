package coplan.solver;

/**
 * Created by afcoplan on 9/22/16.
 */
public class LogicSolver {

    public LogicSolver(){

    }

    public void tryFits(Sudoku sudoku, int[][] squareData){
        int[] missingNumbers = Computations.calculateMissingNumbers(squareData);
    }

    public void tryFits(Sudoku sudoku, int[] data){
        int[] missingNumbers = Computations.calculateMissingNumbers(data);


    }
}
