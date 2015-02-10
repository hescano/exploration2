import java.io.*;
import java.nio.file.Files;
import java.util.*;

public class BubbleSort
{
	public static void sort(int[] pArray)
	{
//        System.out.println(pArray.length);
		int numCompares = pArray.length - 1;

		while (numCompares != 0)
		{
			int last = 1;
			for (int i = 1; i <= numCompares; i++)
			{
				if (pArray[i-1] > pArray[i])
				{
					int temp = pArray[i-1];
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
            sort(arr);
            endTime = System.currentTimeMillis();
            totalTime = (endTime - startTime) / 1000;
            System.out.println("Sorted array size " + i + " in " + totalTime + " seconds");
        }

	}
	
}