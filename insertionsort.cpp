#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
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
	
	std::clock_t start;
	std::clock_t end;
	int size = 50000;
	string filename;
	std::cout << "Target file: ";
	std::cin >> filename;
	
	std::cout << "File size(entry's): ";
	std::cin >> size;
	char CHARarray[size];
	int INTarray[size];
	double DOUBLEarray[size];
	float FLOATarray[size];
	
	ifstream fin(filename.c_str());
	int x;
	for (int i = 0; i < size; i++) {
		fin >> x;
		cout << x;
		CHARarray[i] = x % 26 + 65; //A-Z 
		INTarray[i] = x;
		DOUBLEarray[i] = x + .1;
		FLOATarray[i] =  x + .1;
	}
	fin.close();
	/* generates arrays with number in multiples of 3 % size of the array
	int x = 0;
	int mod = ((size % 3) == 0) * 1 + ((size % 3) == 2) * -1;
	for (int i = 0; i < size; i++) {
		x = (i * 3) % (size + mod);
		CHARarray[i] = x % 26 + 65; //A-Z 
		INTarray[i] = x;
		DOUBLEarray[i] = x + .1;
		FLOATarray[i] =  x + .1;
	}*/
	
	
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
	
	/* test to compare COMPARISON and ASSIGNMENT of varying types
	start = std::clock();
	compcheck('a', 'a');
	end = std::clock();
	std::cout << "COMP CHARS = " << (double)(end - start) / CLOCKS_PER_SEC << '\n';
	
	start = std::clock();
	compcheck(1, 2);
	end = std::clock();
	std::cout << "COMP INTS = " << (double)(end - start) / CLOCKS_PER_SEC << '\n';
	
	start = std::clock();
	compcheck((float)1.1, (float)2.2);
	end = std::clock();
	std::cout << "COMP FLOATS = " << (double)(end - start) / CLOCKS_PER_SEC << '\n';
	
	start = std::clock();
	compcheck((double)1.1, (double)2.2);
	end = std::clock();
	std::cout << "COMP DOUBLES = " << (double)(end - start) / CLOCKS_PER_SEC << '\n';
	
	start = std::clock();
	assigncheck('a');
	end = std::clock();
	std::cout << "ASSIGN CHARS = " << (double)(end - start) / CLOCKS_PER_SEC << '\n';
	
	start = std::clock();
	assigncheck(1);
	end = std::clock();
	std::cout << "ASSIGN INTS = " << (double)(end - start) / CLOCKS_PER_SEC << '\n';
	
	start = std::clock();
	assigncheck((float)1.1);
	end = std::clock();
	std::cout << "ASSIGN FLOATS = " << (double)(end - start) / CLOCKS_PER_SEC << '\n';
	
	start = std::clock();
	assigncheck((double)1.1);
	end = std::clock();
	std::cout << "ASSIGN DOUBLES = " << (double)(end - start) / CLOCKS_PER_SEC << '\n';
	*/
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
