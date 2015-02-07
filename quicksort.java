import java.util.Random;
import java.io.PrintWriter;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class quicksort
{
   public static final int MAX_VALUE = 1000000;
   
   public static void main(String[] args) throws Exception
   {
      int[] arr = new int[MAX_VALUE];
      Stopwatch watch = new Stopwatch();
      
      //Tests the quicksort algorithm with one million consecutive sorted elements 0-999999
      arr = getArrayFromFile("Numbers\\quicksort - sorted.txt");
      quickSort(arr, 0, arr.length - 1);
      watch.end("QuickSort with Sorted Array:");
      
      //Tests the quicksort algorithm with one million almost sorted elements
      arr = getArrayFromFile("Numbers\\quicksort - almostsorted.txt");
      watch = new Stopwatch();
      quickSort(arr, 0, arr.length - 1);
      watch.end("QuickSort with Almost Sorted Array:");
      
      //Tests the quicksort algorithm with one million random elements, with range 0-999999
      arr = getArrayFromFile("Numbers\\quicksort - random.txt");
      watch = new Stopwatch();
      quickSort(arr, 0, arr.length - 1);
      watch.end("QuickSort with Random Sorted Array:");
      
      //Tests the quicksort algorithm with one million consecutive sorted elements 999999-0
      arr = getArrayFromFile("Numbers\\quicksort - reversed sorted.txt");
      watch = new Stopwatch();
      quickSort(arr, 0, arr.length - 1);
      watch.end("QuickSort with Reversed Sorted Array:");
      
      //Tests the quicksort algorithm with one million elements with the same value (1000000)
      arr = getArrayFromFile("Numbers\\quicksort - same.txt");
      watch = new Stopwatch();
      quickSort(arr, 0, arr.length - 1);
      watch.end("QuickSort with same elements in the Array:");
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