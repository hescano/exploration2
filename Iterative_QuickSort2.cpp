#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <ctime>

using namespace std;
 
int Partition(int a[], int left, int right)
{
      int pivot = a[left];
      while (true)
      {
            while (a[left] < pivot)
            left++;
 
            while (a[right] > pivot)
            right--;
 
//          if(a[right] == pivot)
//              continue;
          
        if (left < right)
            {
            int temp = a[right];
            a[right] = a[left];
                  a[left] = temp;
            }
            else
            {
                  return right;
            }
      }
}
 
void QuickSort_Iterative(int *arr, int left, int right)
{
    if(left >= right)
        return; // Invalid index range
 
    std::vector<std::pair<int, int> > list;
 
    int srcleft = left;
    int srcright = right;
 
    list.push_back(std::pair<int, int>(left, right));
 
    while(1)
    {
        if(list.size() == 0)
            break;
 
        left = list.back().first;
        right = list.back().second;
        list.pop_back();
 
        int pivot = Partition(arr, left, right);   
       
        std::pair<int,int> p;
        if(pivot > 1)
            list.push_back(std::pair<int, int>(left, pivot - 1));
 
        if(pivot + 1 < right)
            list.push_back(std::pair<int, int>(pivot + 1, right));
    }
}
 
void QuickSortHelper(int *arr, int len)
{
    //QuickSort_Recursive(arr, 0, len - 1);    
    QuickSort_Iterative(arr, 0, len - 1);
}
 
 
 
int main()
{
    cout << "Iterative QuickSort By Iterative Method\n";

        std::clock_t start;
        std::clock_t end;
        
        vector<int> vec;
        
        ifstream fin ("Numbers/numbers.txt"); //file

        int temp = 0;
        while (!fin.eof())
        {
            fin >> temp;
            vec.push_back(temp);
        }
        fin.close();
        
//        int len = vec.size();
        int len = 160;
        int num = len;
        int numbers[len];
        
        
        for(int i = 0; i < len; ++i) {
            numbers[i] = vec[i];
//            numbers[i] = num;
//            num--;
        }
        
        for (int i = 0; i < len; i++)
            cout << numbers[i] << " ";
        cout << endl;

		start = std::clock();
		QuickSort_Iterative(numbers, 0, len - 1);
		end = std::clock();
        std::cout << "Time to sort = " << (double)(end - start) / CLOCKS_PER_SEC << endl;

		for (int i = 0; i < len; i++)
		  cout << numbers[i] << " ";
        cout << endl;
        
        return 0;
}