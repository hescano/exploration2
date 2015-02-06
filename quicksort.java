public class quicksort
{
   public static void main(String[] args)
   {
      int[] arr = {45,22, 233, 55, 43, 54, 32 };
      System.out.println(java.util.Arrays.toString(arr));
      Stopwatch watch = new Stopwatch(); //this constructor starts automatically
      quickSort(arr, 0, arr.length - 1);
      watch.end("QuickSort");
      System.out.println(java.util.Arrays.toString(arr));
   }
   
   public static void quickSort(int[] arr, int start, int end)
   {
      int index = partition(arr, start, end);
      
      if (start < index  - 1)
      {
         quickSort(arr, start, index - 1);
      }
      
      if (end > index)
      {
         quickSort(arr, index, end);
      }
   }
   
   public static int partition(int[] arr, int left, int right)
   {
      int pivot = arr[left];
      
      while (left <= right)
      {
         while (arr[left] < pivot)
         {
            left++;
         }
         
         while (arr[right] > pivot)
         {
            right--;
         }
         
         //swap
         if (left <= right)
         {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            left++;
            right--;
         }
      }
      
      return left;
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