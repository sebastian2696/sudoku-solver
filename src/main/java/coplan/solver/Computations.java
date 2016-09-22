package coplan.solver;

import coplan.io.Output;

/**
 * Created by afcoplan on 9/22/16.
 */
public class Computations {

    private int[] defaultNumbers = {1,2,3,4,5,6,7,8,9};

    public static int[] calculateMissingNumbers(int[] data){
        int[] occurrences = new int[9];

        for(int i : data){
            if(i != 0){
                occurrences[i-1]++;
            }
        }

        return determineMissingNumbers(occurrences);
    }

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
