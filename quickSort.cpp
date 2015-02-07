#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

template<class t>
int choosePivot(t A[], int lo, int hi)
{
   return hi - lo + lo;
}

template<class t>
int partition(t A[], int lo, int hi)
{
   int pivotIndex = choosePivot(A, lo, hi);
   t pivotValue = A[pivotIndex];
   
   t temp = A[pivotIndex];
   A[pivotIndex] = A[hi];
   A[hi] = temp;

   int storeIndex = lo;

   for (int i = lo; i < hi; i++)
   {
      if (A[i] < pivotValue)
      {
         temp = A[i];
         A[i] = A[storeIndex];
         A[storeIndex] = temp;
         storeIndex += 1;
      }
   }
   temp = A[storeIndex];
   A[storeIndex] = A[hi];
   A[hi] = temp;

   return storeIndex;
}

template<class t>
void quicksort(t A[], int lo, int hi)
{
   if (lo < hi)
   {
      int p = partition(A, lo, hi);
      quicksort(A, lo, p - 1);
      quicksort(A, p + 1, hi);
   }
}

int main()
{
   clock_t start;
   clock_t end;
   
   //change these three based on the file
   int SIZE1 = 15000; //number of items
   int TEST_ARRAY1[15000]; //number of items
   ifstream fin ("numbers15.txt"); //file

   int temp = 0;
   for (int i = 0; i < SIZE1; i++)
   {
      fin >> temp;
      TEST_ARRAY1[i] = temp;
   }
   fin.close();

   start = clock();
   quicksort(TEST_ARRAY1, 0, SIZE1 - 1);
   end = clock();
   
   cout << (double)(end - start)/CLOCKS_PER_SEC;
   
   return 0;
}