import java.io.*;
import java.nio.file.Files;
import java.util.*;

public class quicksort
{
   public static final int MAX_VALUE = 1000000;
   
   public static void main(String[] args) throws Exception
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
            quickSort(arr, 0, arr.length - 1);
            endTime = System.currentTimeMillis();
            totalTime = (endTime - startTime) / 1000;
            System.out.println("Sorted array size " + i + " in " + totalTime + " seconds");
        }
   }
   
   public static int[] getArrayFromFile(String fileName)
   {
      int[] arr = new int[MAX_VALUE];
      try
      {
         BufferedReader reader = new BufferedReader(new FileReader(fileName));
         String line = null;
         Scanner scanner = null;
         int index = 0;
         
         while ((line = reader.readLine()) != null) {
            scanner = new Scanner(line);
            scanner.useDelimiter(", ");
            
            while (scanner.hasNext()) {
               arr[index++] = scanner.nextInt();
            }
            index = 0;
         }
      }
      catch(IOException e)
      {}
      return arr;
   }
   
   public static void quickSort(int[] arr, int left, int right)
   {

      int i = left;
      int j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

      while (i <= j)
      {
         while (arr[i] < pivot)
            i++;
         while (arr[j] > pivot)
            j--;
         
         if (i <= j)
         {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
         }
      }

      if (left < j)
         quickSort(arr, left, j);
      if (i < right)
         quickSort(arr, i, right);
   }
}

class Stopwatch 
{
   static long startTime;
   static long splitTime;
   static long endTime;

   public Stopwatch() 
   {
      start();
   }

   public void start() 
   {
      startTime = System.currentTimeMillis();
      splitTime = System.currentTimeMillis();
      endTime = System.currentTimeMillis();
   }

   public void split() 
   {
      split("");
   }

   public void split(String tag) 
   {
      endTime = System.currentTimeMillis();
      System.out.println("Split time for [" + tag + "]: " + (endTime - splitTime) + " ms");
      splitTime = endTime;
   }

   public void end() 
   {
      end("");
   }
   
   public void end(String tag) 
   {
      endTime = System.currentTimeMillis();
      System.out.println("Final time for [" + tag + "]: " + (endTime - startTime) + " ms");
   }
}