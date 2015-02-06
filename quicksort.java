public class quicksort
{
   public static void main(String[] args)
   {
      int[] arr = {45,22, 233, 55, 43, 54, 32 };
      System.out.println(java.util.Arrays.toString(arr));
      sort(arr, 0, arr.length - 1);
      System.out.println(java.util.Arrays.toString(arr));
   }
   
   public static void sort(int[] arr, int start, int end)
   {
      int index = partition(arr, start, end);
      
      if (start < index  - 1)
      {
         sort(arr, start, index - 1);
      }
      
      if (end > index)
      {
         sort(arr, index, end);
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
