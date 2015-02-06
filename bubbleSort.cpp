#include <iostream>
using namespace std;

void sort(int pArray[], int pLength)
{
   int numCompares = pLength - 1;

   while (numCompares != 0)
   {
      int last = 1;
      for (int i = 1; i <= numCompares; i++)
      {
         if (pArray[i - 1] > pArray[i])
         {
            int temp = pArray[i - 1];
            pArray[i - 1] = pArray[i];
            pArray[i] = temp;
            last = i;
         }
      }
      numCompares = last - 1;
   }
}
int main()
{
   int arr[] = { 45, 22, 233, 55, 43, 54, 32 };
   int length = sizeof(arr)/sizeof(arr[0]);
   for (int i = 0; i < length; i++)
      cout << arr[i] << " , ";
   cout << endl;
   sort(arr,length);
   for (int i = 0; i < length; i++)
      cout << arr[i] << " , ";
   cout << endl;
   return 0;
}

