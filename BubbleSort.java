public class BubbleSort
{
	public static void sort(int[] pArray)
	{
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
	
	public static void main(String args[])
	{
		int[] arr = {45,22, 233, 55, 43, 54, 32 };
		System.out.println(java.util.Arrays.toString(arr));
		sort(arr);
		System.out.println(java.util.Arrays.toString(arr));
	}
}