package coplan.io;

import coplan.solver.Sudoku;

import java.io.File;
import java.util.Scanner;

/**
 * Created by afcoplan on 9/20/16.
 */
public class SudokuFileReader {

    public static Sudoku readFile(String filepath){
        try {
            File file = new File(filepath);

            Scanner sc = new Scanner(file);

            int[][] sudokuData = new int[9][9];

            for(int row = 0; row < 9; row++){
                char[] linechars = sc.nextLine().toCharArray();
                int col = 0;
                for(char character : linechars){
                    if(col == 9){
                        break;
                    }

                    sudokuData[row][col] = Integer.parseInt(new String(character + ""));
                    col++;
                }
            }

            return new Sudoku(sudokuData);

        }catch(Exception e){
            System.out.println("Error reading input from file!");
            System.exit(-1);
            return null;
        }
    }
}
