#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>

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
            sort(numbers, len);
            end = std::clock();
            cout << "Time to sort " << len << " elements = " << (double)(end - start) / CLOCKS_PER_SEC << endl;

        }
        return 0;
}

