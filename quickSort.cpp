#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>

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
   cout << "Iterative QuickSort By Iterative Method\n";

        vector<string> files;
        
        files.push_back("Numbers/numbers1000.txt");
        files.push_back("Numbers/numbers100.txt");
        files.push_back("Numbers/numbers50.txt");
        files.push_back("Numbers/numbers45.txt");
        files.push_back("Numbers/numbers40.txt");
        files.push_back("Numbers/numbers35.txt");
        files.push_back("Numbers/numbers30.txt");
        files.push_back("Numbers/numbers25.txt");
        files.push_back("Numbers/numbers20.txt");
        files.push_back("Numbers/numbers15.txt");
        files.push_back("Numbers/numbers.txt");
        
        
        std::clock_t start;
        std::clock_t end;
        
        vector<int> vec;
        while(files.size() > 0)
        {
            vec.clear();
            
            ifstream fin (files.back()); //file
            files.pop_back();
            int temp = 0;

            while (!fin.eof())
            {
                fin >> temp;
                vec.push_back(temp);
            }
            fin.close();

            int len = vec.size();
            int numbers[len];        

            for(int i = 0; i < len; ++i) {
                numbers[i] = vec[i];
            }

            start = std::clock();
            quicksort(numbers, 0, len - 1);
            end = std::clock();
            cout << "Time to sort " << len << " elements = " << (double)(end - start) / CLOCKS_PER_SEC << endl;

        }
        return 0;
}