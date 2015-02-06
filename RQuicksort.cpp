//============================================================================
// Name        : RQuicksort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>    //cout
#include <cstdlib>     //rand()
#include <ctime>       //clock

using namespace std;

template<class T>
void swap(T array[], int startPos, int endPos) {
	T temp = array[startPos];
	array[startPos] = array[endPos];
	array[endPos] = temp;
}

//-----------------------------------------------------------------------------------------
//  quicksort()
//  recursively sorts divided lists
//-----------------------------------------------------------------------------------------

template<class T>
void quickSort(T array[], int left, int right) {
	int i = left;
	int j = right;
	int tmp;
	int pivot = array[(left + right) / 2];

	while (i <= j) {
		while (array[i] < pivot) // as long as the member is less then the pivot, continue
			i++;
		while (array[j] > pivot)
			j--;
		if (i <= j) {
			swap(array, i, j);
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSort(array, left, j);
	if (i < right)
		quickSort(array, i, right);
}

template<class T>
void randomize(T array[], int length) {
	for (int i = 0; i < length; ++i) {
		int randInt = rand() % length;
		swap(array, i, randInt);
	}
}

template<class T>
void display() {

}

template<class T>
void fillArray(T array[], int length) {
	for (int i = 0; i < length; ++i) {
		array[i] = (T) i * 1.0;
	}

	randomize(array, length);
}

//-----------------------------------------------------------------------------------------
//  main()
//  test driver for quicksort
//-----------------------------------------------------------------------------------------
int main() {

	int INITIAL_SIZE = 10000;
	int MAX_SIZE     = 50000;
	int INCREMENT    = 5000;

	cout << "Integer Testing" << endl;
	for (int ARRAY_SIZE = INITIAL_SIZE; ARRAY_SIZE <= MAX_SIZE; ARRAY_SIZE +=
			INCREMENT) {
		int intArray[ARRAY_SIZE];
		fillArray(intArray, ARRAY_SIZE);

		int start = clock();
		quickSort(intArray, 0, ARRAY_SIZE);
		int stop = clock();

		cout << "Size: " << ARRAY_SIZE << "  Time: "
				<< (stop - start) / double(CLOCKS_PER_SEC) * 1000 << endl;
	}

	cout << endl << endl;

	cout << "Float Testing" << endl;
	for (int ARRAY_SIZE = INITIAL_SIZE; ARRAY_SIZE <= MAX_SIZE; ARRAY_SIZE +=
			INCREMENT) {
		float intArray[ARRAY_SIZE];
		fillArray(intArray, ARRAY_SIZE);

		int start = clock();
		quickSort(intArray, 0, ARRAY_SIZE);
		int stop = clock();

		cout << "Size: " << ARRAY_SIZE << "  Time: "
				<< (stop - start) / double(CLOCKS_PER_SEC) * 1000 << endl;
	}

	cout << endl << endl;

	cout << "Double Testing" << endl;
	for (int ARRAY_SIZE = INITIAL_SIZE; ARRAY_SIZE <= MAX_SIZE; ARRAY_SIZE +=
			INCREMENT) {
		double intArray[ARRAY_SIZE];
		fillArray(intArray, ARRAY_SIZE);

		int start = clock();
		quickSort(intArray, 0, ARRAY_SIZE);
		int stop = clock();

		cout << "Size: " << ARRAY_SIZE << "  Time: "
				<< (stop - start) / double(CLOCKS_PER_SEC) * 1000 << endl;
	}

	return EXIT_SUCCESS;
}
