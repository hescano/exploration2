#include <iostream>

#include <fstream>

#include <stdlib.h>
#include <time.h>

using namespace std;


int main()
{
   //change the amount of numbers
   int SIZE = 1000000;
   srand (time(NULL));

   ofstream fout;
   fout.open("numbers1000.txt");

   int number = 0;
   for (int i = 0; i < SIZE; i++)
   {
      fout << (rand() % SIZE + 1) << endl;
   }

   fout.close();

   return 0;
}