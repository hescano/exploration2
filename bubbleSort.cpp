// Read for tests

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

template <typename T>
void sort(T pArray[], int pLength)
{
   int numCompares = pLength - 1;

   while (numCompares != 0)
   {
      int last = 1;
      for (int i = 1; i <= numCompares; i++)
      {
         if (pArray[i - 1] > pArray[i])
         {
            T temp = pArray[i - 1];
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
   std::clock_t start;
   std::clock_t end;
   int size = 50000;
   string filename;
   std::cout << "Target file: ";
   std::cin >> filename;

   std::cout << "File size(entry's): ";
   std::cin >> size;
   char *CHARarray = new char[size];
   int *INTarray = new int[size];
   double *DOUBLEarray = new double[size];
   float *FLOATarray = new float[size];

   ifstream fin(filename.c_str());
   int x;
   for (int i = 0; i < size; i++) {
      fin >> x;
      cout << x;
      CHARarray[i] = x % 26 + 65; //A-Z 
      INTarray[i] = x;
      DOUBLEarray[i] = x + .1;
      FLOATarray[i] = x + .1;
   }
   fin.close();
   
   start = std::clock();
   sort(CHARarray, size);
   end = std::clock();
   std::cout << "SORT CHARS = " << (double)(end - start) / CLOCKS_PER_SEC << '\n';

   start = std::clock();
   sort(INTarray, size);
   end = std::clock();
   std::cout << "SORT INTS = " << (double)(end - start) / CLOCKS_PER_SEC << '\n';

   start = std::clock();
   sort(FLOATarray, size);
   end = std::clock();
   std::cout << "SORT FLOATS = " << (double)(end - start) / CLOCKS_PER_SEC << '\n';

   start = std::clock();
   sort(DOUBLEarray, size);
   end = std::clock();
   std::cout << "SORT DOUBLES = " << (double)(end - start) / CLOCKS_PER_SEC << '\n';

   cout << "End of Compare\n";
   return 0;
}

