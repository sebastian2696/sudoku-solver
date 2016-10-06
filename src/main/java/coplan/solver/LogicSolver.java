package coplan.solver;

/**
 * Class for solution related methods such as inserting numbers,
 * checking possibilities, validating sudokus, solution logic.
 */
public class LogicSolver {

    public LogicSolver(){

    }

    // INCOMPLETE: attempting to insert numbers within a square
    public void trySquareFits(Sudoku sudoku, int verticalIndex, int horizontalIndex){
        int[][] squareData = sudoku.getSquare(verticalIndex, horizontalIndex);
        int[] missingNumbers = Computations.calculateMissingNumbers(squareData);

        boolean breakLoop = false;

        for(int attemptedInsertion : missingNumbers){

            System.out.println("Attempting to insert " + attemptedInsertion + ":");

            for(int row = 0; row < squareData.length; row++){
                for(int col = 0; col < squareData[0].length; col++){
                    if(squareData[row][col] == 0){
                        // insert the number
                        squareData[row][col] = attemptedInsertion;

                        // check whether or not it is the only place it can go
                        boolean success = onlyOption();

                        // if it can go there, leave it and break both inner for loops
                        // if it can't go there, change squareData[row][col] back to zero and continue the loop
                        if(success){
                            System.out.println("Successfully inserted " + attemptedInsertion + " into its only possibility.");
                            breakLoop = true;
                            break;
                        }else{
                            squareData[row][col] = 0;
                        }
                    }
                }
                if(breakLoop){
                    breakLoop = false;
                    break;
                }
            }
        }
    }

    // MISSING: need tryColFits(Sudoku sudoku, int colNumber)

    // INCOMPLETE: attempting to insert numbers within a row
    public void tryRowFits(Sudoku sudoku, int rowNumber){
        int[] rowData = sudoku.getRow(rowNumber);
        int[] missingNumbers = Computations.calculateMissingNumbers(rowData);

        for(int attemptedInsertion : missingNumbers){
            for(int i = 0; i < rowData.length; i++){
                if(rowData[i] == 0){
                    // insert the number
                    rowData[i] = attemptedInsertion;

                    // check whether or not it is the only place it can go
                    boolean success = onlyOption();

                    // if it can go there, leave it and break this inner for loop
                    // if it can't go there, change rowData[i] back to zero and continue the loop
                    if(success){
                        break;
                    }else{
                        rowData[i] = 0;
                    }
                }
            }
        }
    }

    // INCOMPLETE: checks if a position is the only spot a number can go in a given row, col, or square
    private boolean onlyOption(){
        return false;
    }
}
