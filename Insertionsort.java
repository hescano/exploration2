package insertionsort;

import java.util.concurrent.TimeUnit;

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
	public static void main(String[] args) {
		int size = 50000;
		double startTime = 0;
		double endTime = 0;
		double totalTime = 0;
		Character CHARarray[] = new Character[size];
		Integer INTarray[] = new Integer[size];
		Double DOUBLEarray[] = new Double[size];
		Float FLOATarray[] = new Float[size];
		int x = 0;
		int mod = 0;
		if ((size % 3) == 0)
			mod = 1;
		if ((size % 3) == 2)
			mod = -1;

		for (int i = 0; i < size; i++) {
			x = (i * 3) % (size + mod);
			CHARarray[i] = (char) (x % 26 + 65); //A-Z 
			INTarray[i] = x;
			DOUBLEarray[i] = x + .1;
			FLOATarray[i] =  (float)(x + .1);
		}
		
		
		char carray[] = new char[size];
		for (int i  = 0; i< size; i++) {
			carray[i] = CHARarray[i];
		}
		int iarray[] = new int[size];
		for (int i  = 0; i< size; i++) {
			iarray[i] = INTarray[i];
		}
		float farray[] = new float[size];
		for (int i  = 0; i< size; i++) {
			farray[i] = FLOATarray[i];
		}
		double darray[] = new double[size];
		for (int i  = 0; i< size; i++) {
			darray[i] = DOUBLEarray[i];
		}
		
		startTime = System.currentTimeMillis();
		sort(CHARarray, size);
		endTime = System.currentTimeMillis();
		totalTime = (endTime - startTime) / 1000;
		System.out.println("SORT CHAR " + totalTime);
		
		
		startTime = System.currentTimeMillis();
		sort(INTarray, size);
		endTime = System.currentTimeMillis();
		totalTime = (endTime - startTime) / 1000;
		System.out.println("SORT INT " + totalTime);
		
		
		startTime = System.currentTimeMillis();
		sort(FLOATarray, size);
		endTime = System.currentTimeMillis();
		totalTime = (endTime - startTime) / 1000;
		System.out.println("SORT FLOAT " + totalTime);
		
		
		startTime = System.currentTimeMillis();
		sort(DOUBLEarray, size);
		endTime = System.currentTimeMillis();
		totalTime = (endTime - startTime) / 1000;
		System.out.println("SORT DOUBLE " + totalTime);
		
		startTime = System.currentTimeMillis();
		csort(carray, size);
		endTime = System.currentTimeMillis();
		totalTime = (endTime - startTime) / 1000;
		System.out.println("SORT char " + totalTime);
		
		
		startTime = System.currentTimeMillis();
		isort(iarray, size);
		endTime = System.currentTimeMillis();
		totalTime = (endTime - startTime) / 1000;
		System.out.println("SORT int " + totalTime);
		
		
		startTime = System.currentTimeMillis();
		fsort(farray, size);
		endTime = System.currentTimeMillis();
		totalTime = (endTime - startTime) / 1000;
		System.out.println("SORT float " + totalTime);
		
		
		startTime = System.currentTimeMillis();
		dsort(darray, size);
		endTime = System.currentTimeMillis();
		totalTime = (endTime - startTime) / 1000;
		System.out.println("SORT double " + totalTime);
	}
	
}
