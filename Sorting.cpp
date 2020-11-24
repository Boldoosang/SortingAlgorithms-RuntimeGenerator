#include <iostream>
#include <cstdlib>
#include <ctime>

#include "MaxHeap.h"
#include "SortAlgorithms.h"

   using namespace std;

//Function Prototypes
int *generateUnsortedInts(int n);

int main () {
	srand(2611);
	
	int *smallArray = generateUnsortedInts(10000);
	int *mediumArray = generateUnsortedInts(1000000);
	int *largeArray = generateUnsortedInts(100000000);
	
	clock_t startSort, endSort;

	startSort = clock();
	
	quickSort(largeArray, 0, 99999999);
	
	endSort = clock();
	
	
	double timeToSort = (double)(endSort - startSort)/CLOCKS_PER_SEC;
	
	cout << timeToSort << endl;

	return 0;
}


int *generateUnsortedInts(int n){
	int *newArray = (int *)calloc(n, sizeof(int));
	for(int i = 0; i < n; i++)
		newArray[i] = rand() % 1000000000 + 1;
	
	return newArray;
}
