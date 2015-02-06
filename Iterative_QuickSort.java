import java.io.*;
import java.util.*;
import java.lang.*;

/*****************************************************************************
* Iterative_QuickSort Class
*****************************************************************************/
class Iterative_QuickSort {

   /*****************************************************************************
   * QuickPosInfo Class
   *****************************************************************************/
	public static class QuickPosInfo
	{
		public int left;
		public int right;
	};

	public static QuickPosInfo info = new QuickPosInfo();

	/*****************************************************************************
	* QuickSort_Iterative()
	*****************************************************************************/
	public static void QuickSort_Iterative(int[] numbers, int left, int right)
	{
		if(left >= right)
			return; // Invalid index range

		LinkedList<QuickPosInfo> list = new LinkedList< QuickPosInfo>();

		info.left = left;
		info.right = right;
		list.add(info);

		// stuff
		while(true)
		{
			if(list.size() == 0)
				break;
		
      		left = list.get(0).left;
			right = list.get(0).right;
			list.remove(0);

         int pivot = numbers[left];
         int tempLeft = left;
         int tempRight = right;
         
         // stuff
         while (true)
         {
            while (numbers[tempLeft] < pivot) 
               tempLeft++;

            while (numbers[tempRight] > pivot) 
               tempRight--;

            if (tempLeft < tempRight)
            {
               int temp = numbers[tempRight];
               numbers[tempRight] = numbers[tempLeft];
               numbers[tempLeft] = temp;
            }
            else
            {
               pivot = tempRight;
               break;
            }
         }

			if(pivot > 1)
			{
				info.left = left;
				info.right = pivot - 1;
				list.add(info);
			}

			if(pivot + 1 < right)
			{
				info.left = pivot + 1;
				info.right = right;
				list.add(info);
			}
		}
	}

	/*****************************************************************************
	* Main()
	*****************************************************************************/
	public static void main(String[] args)
	{
		int[] numbers = { 3, 8, 7, 5, 2, 1, 9, 6, 4 };
		int len = 9;

		System.out.println();
		System.out.println("Iterative QuickSort By Iterative Method");

		Stopwatch watch = new Stopwatch(); //this constructor starts automatically
		QuickSort_Iterative(numbers, 0, len - 1);
		watch.end("Iterative QuickSort");

		for (int i = 0; i < 9; i++)
		  System.out.println(numbers[i]);
	}
}

/*****************************************************************************
* Time Class
*****************************************************************************/
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