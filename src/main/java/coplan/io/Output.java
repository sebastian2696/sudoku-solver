package coplan.io;

/**
 * Created by afcoplan on 9/20/16.
 */
public class Output {

    public static void printArray(int[][] array){
        for(int row = 0; row < array.length; row++){
            for(int col = 0; col < array[0].length; col++){
                System.out.print(array[row][col] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void printArray(int[] array){
        for(int i = 0; i < array.length; i++){
            System.out.print(array[i] + " ");
        }

        System.out.println();
        System.out.println();
    }

    public static void printVerticalArray(int[] array){
        for(int i = 0; i < array.length; i++){
            System.out.println(array[i]);
        }
        System.out.println();
    }
}
