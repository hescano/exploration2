#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

/*
 * Algorithum found on: http://en.wikibooks.org/wiki/Algorithm_Implementation/Sorting/Merge_sort#C.2B.2B
 */
 
void merge(int a[], const int low, const int mid, const int high)
{
	// Variables declaration. 
	int * b = new int[high+1-low];
	int h,i,j,k;
	h=low;
	i=0;
	j=mid+1;
	// Merges the two array's into b[] until the first one is finish
	while((h<=mid)&&(j<=high))
	{
		if(a[h]<=a[j])
		{
			b[i]=a[h];
			h++;
		}
		else
		{
			b[i]=a[j];
			j++;
		}
		i++;
	}
	// Completes the array filling in it the missing values
	if(h>mid)
	{
		for(k=j;k<=high;k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	else
	{
		for(k=h;k<=mid;k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	// Prints into the original array
	for(k=0;k<=high-low;k++) 
	{
		a[k+low]=b[k];
	}
	delete[] b;
}
 
void sort( int a[], const int low, const int high )
{
	int mid;
	if( low < high )
	{
		mid = ( low + high ) / 2;
		sort( a, low, mid );
		sort( a, mid + 1, high );
		merge( a, low, mid, high );
	}
}
 
int main()
{
	cout << "Merge Sort\n";

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
            sort(numbers, 0, len - 1);
            end = std::clock();
            cout << "Time to sort " << len << " elements = " << (double)(end - start) / CLOCKS_PER_SEC << endl;

        }
        return 0;
}