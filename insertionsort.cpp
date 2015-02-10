#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

template <typename T>
void sort(T array[], int size);
template <typename T>
void display (T array[], int size);
template <typename T>
void compcheck (T a, T b);
template <typename T>
void assigncheck (T a);

int main() {
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

void wait(int n) {
	for (int i = 0; i < n; i++) {}
}

template <typename T>
void sort(T array[], int size) {
	T x = 0;
	int j = 1;
	for (int i = 1; i < size; i++) {
		x = array[i];
		j = i;
		for (; j > 0 && array[j - 1] > x; j--) {
			array[j] = array[j - 1];
			//wait(0);
		}
		array[j] = x;
	}
	//display(array, size); 
}

template <typename T>
void display (T array[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout << array[i] << ' ';}
	std::cout << std::endl;
}

template <typename T>
void compcheck (T a, T b) {
	bool nothing;
	for (int c = 0; c < 10; c++) {
		for (long int i = 0; i < 1000000000; i++) {
			nothing = a < b;		
		}
	}
}

template <typename T>
void assigncheck (T a) {
	T nothing[1];
	for (int c = 0; c < 10; c++) {
		for (long int i = 0; i < 1000000000; i++) {
			nothing[0] = a;		
		}
	}
}
