package coplan.solver;

/**
 * Computations contains methods for calculating the missing numbers of a
 * row, column, or square.  Also contains general methods for computing a
 * result from an int[] or int[][].
 */
public class Computations {

    // in any sudoku, the default numbers are digits 1-9
    private int[] defaultNumbers = {1,2,3,4,5,6,7,8,9};

    // calculates what numbers in the range 1-9 are missing from a row or col
    public static int[] calculateMissingNumbers(int[] data){
        int[] occurrences = new int[9];

        for(int i : data){
            if(i != 0){
                occurrences[i-1]++;
            }
        }

        return determineMissingNumbers(occurrences);
    }

    // calculates what numbers in the range 1-9 are missing from a square
    public static int[] calculateMissingNumbers(int[][] data){
        int[] occurrences = new int[9];

        for(int row = 0; row < data.length; row++){
            for(int col = 0; col < data[0].length; col++){
                int i = data[row][col];

                if(i != 0){
                    occurrences[i-1]++;
                }
            }
        }

        return determineMissingNumbers(occurrences);
    }

    // helper method for calculateMissingNumbers()
    private static int[] determineMissingNumbers(int[] occurrences){
        int missingNumbersSize = countOccurrencesOfZero(occurrences);
        int[] missingNumbers = new int[missingNumbersSize];

        int index = 0;

        for(int i = 0; i < occurrences.length; i++){
            if(occurrences[i] == 0){
                missingNumbers[index] = i + 1;
                index++;
            }
        }

        return missingNumbers;
    }

    // helper method to count number of zeros in an array
    private static int countOccurrencesOfZero(int[] occurrences){
        int count = 0;

        for(int i : occurrences){
            if(i == 0){
                count++;
            }
        }

        return count;
    }
}
