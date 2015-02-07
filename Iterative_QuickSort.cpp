// Done
// WARNIING: This will NOT work with duplicates, and cannot work with them.

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

/*****************************************************************************
   * QuickPosInfo Class
   *****************************************************************************/
    struct QuickPosInfo
	{
		public:
            int left;
            int right;
	};

	/*****************************************************************************
	* QuickSort_Iterative()
	*****************************************************************************/
	void QuickSort_Iterative(int numbers[], int left, int right)
	{
        QuickPosInfo info;
        
		if(left >= right)
			return; // Invalid index range

//		LinkedList<QuickPosInfo> list = new LinkedList< QuickPosInfo>();
        vector<QuickPosInfo> list;

		info.left = left;
		info.right = right;
		list.push_back(info);

		// stuff
		while(true)
		{
			if(list.size() == 0)
				break;
            
      		left = list.at(0).left;
			right = list.at(0).right;
			list.erase(list.begin());

         int pivot = numbers[left + ((right - left) / 2)];
//            cout << "pivot = " << pivot << endl;
         int tempLeft = left;
         int tempRight = right;
         
         // stuff
         while (true)
         {
            while (numbers[tempLeft] < pivot) 
               tempLeft++;

            while (numbers[tempRight] > pivot) 
               tempRight--;
             
//             cout << "left: " << tempLeft << " right: " << tempRight << endl;
             
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
				list.push_back(info);
			}
            

			if(pivot + 1 < right)
			{
				info.left = pivot + 1;
				info.right = right;
				list.push_back(info);
			}
		}
	}

	/*****************************************************************************
	* Main()
	*****************************************************************************/
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
        int len = 10;
//        int num = len;
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