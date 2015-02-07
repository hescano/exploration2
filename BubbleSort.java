import java.io.*;
import java.nio.file.Files;
import java.util.Scanner;

public class BubbleSort
{
	public static <T extends Comparable <T>> void sort(T[] pArray,int pLength)
	{
		int numCompares = pArray.length - 1;

		while (numCompares != 0)
		{
			int last = 1;
			for (int i = 1; i <= numCompares; i++)
			{
				if (pArray[i-1].compareTo(pArray[i]) == -1)
				{
					T temp = pArray[i-1];
					pArray[i-1] = pArray[i];
					pArray[i] = temp;
					last = i;
				}
			}
			numCompares = last - 1;
		}
		
	}
	
	public static void main(String args[]) throws FileNotFoundException
	{
		int size = 10000;
		double startTime = 0;
		double endTime = 0;
		double totalTime = 0;
		Character CHARarray[] = new Character[size];
		Integer INTarray[] = new Integer[size];
		Double DOUBLEarray[] = new Double[size];
		Float FLOATarray[] = new Float[size];
		
		//Change for file input
		Scanner scan = new Scanner(new File("num.txt"));
		for (int i = 0; scan.hasNextInt(); i++) 
		{
			int x = scan.nextInt();
				//	(i * 3) % (size + mod);
			CHARarray[i] = (char) (x % 26 + 65); //A-Z 
			INTarray[i] = x;
			DOUBLEarray[i] = x + .1;
			FLOATarray[i] =  (float)(x + .1);
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
		System.out.println("End of Compare");
	}
	
}