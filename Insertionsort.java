import java.io.*;
import java.nio.file.Files;
import java.util.*;

/**
 *
 * @author McAllister
 */
public class Insertionsort {

	public static <T extends Comparable<T>> void sort( T[] array, int size) {
		T x;
		int j = 1;
		for (int i = 1; i < size; i++) {
			x = array[i];
			j = i;
			for (; j > 0 && (array[j - 1].compareTo(x) > 0); j--) {
				array[j] = array[j - 1];
				//wait(0);
			}
			array[j] = x;
		}
	}
	
	public static void csort( char[] array, int size) {
		char x;
		int j = 1;
		for (int i = 1; i < size; i++) {
			x = array[i];
			j = i;
			for (; j > 0 && (array[j - 1] > x); j--) {
				array[j] = array[j - 1];
				//wait(0);
			}
			array[j] = x;
		}
	}
	
	public static void isort( int[] array, int size) {
		int x;
		int j = 1;
		for (int i = 1; i < size; i++) {
			x = array[i];
			j = i;
			for (; j > 0 && (array[j - 1] > x); j--) {
				array[j] = array[j - 1];
				//wait(0);
			}
			array[j] = x;
		}
	}
	
	public static void fsort( float[] array, int size) {
		float x;
		int j = 1;
		for (int i = 1; i < size; i++) {
			x = array[i];
			j = i;
			for (; j > 0 && (array[j - 1] > x); j--) {
				array[j] = array[j - 1];
				//wait(0);
			}
			array[j] = x;
		}
	}
	
	public static void dsort( double[] array, int size) {
		double x;
		int j = 1;
		for (int i = 1; i < size; i++) {
			x = array[i];
			j = i;
			for (; j > 0 && (array[j - 1] > x); j--) {
				array[j] = array[j - 1];
				//wait(0);
			}
			array[j] = x;
		}
	}
	public static void main(String[] args) throws FileNotFoundException
    {
		List<String> files = new ArrayList<String>();
        
        files.add("Numbers/numbers.txt");
        files.add("Numbers/numbers15.txt");
        files.add("Numbers/numbers20.txt");
        files.add("Numbers/numbers25.txt");
        files.add("Numbers/numbers30.txt");
        files.add("Numbers/numbers35.txt");
        files.add("Numbers/numbers40.txt");
        files.add("Numbers/numbers45.txt");
        files.add("Numbers/numbers50.txt");
        files.add("Numbers/numbers100.txt");
        files.add("Numbers/numbers1000.txt");
        
		int size = 1000000;
		double startTime = 0;
		double endTime = 0;
		double totalTime = 0;

		int array[] = new int[size];

        //Change for file input
        for(int j = 0; j < files.size(); j++)
        {
            Scanner scan = new Scanner(new File(files.get(j)));

            int i = 0;
            for (; scan.hasNextInt(); i++) { array[i] = scan.nextInt(); }

            int[] arr = Arrays.copyOf(array, i);

            startTime = System.currentTimeMillis();
            isort(arr, arr.length);
            endTime = System.currentTimeMillis();
            totalTime = (endTime - startTime) / 1000;
            System.out.println("Sorted array size " + i + " in " + totalTime + " seconds");
        }
    }
	
}
