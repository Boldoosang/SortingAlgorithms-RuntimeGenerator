//Justin Baldeosingh
//COMP 2611 - Data Structures
//Group Research Project - Analysis of Sorting Algorithms
//Personal Sandbox

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <iomanip>
#include <cmath>

#include "MaxHeap.h"
#include "SortAlgorithms.h"

   using namespace std;

struct data {
	int key;
	char words[500];
};


//Function Prototypes
int *generateUnsortedInts(int n);
Unit *generateStructData(int n);
int **generateDataset(int increment, int n);
int **generateExpDataset(int increment, int mult, int n);
void releaseMemory(int **datasets, int n);
void reverseData(int A[], int n);
void exponentialAnalysis(int numDatasets, int startDatasetSize, int multiplyDatasetSize);
void linearAnalysis(int numDatasets, int startDatasetSize, int incrementDatasetSize);
void structSortAnalysis(int numDatasets, int startDatasetSize, int incrementDatasetSize);

int main () {
	//Comment out the different types of analysis if you are seeking to 
	exponentialAnalysis(30, 10, 2);
	linearAnalysis(20, 0, 10000);
	structSortAnalysis(6, 0, 10000);
	
	return 0;
}

void exponentialAnalysis(int numDatasets, int startDatasetSize, int multiplyDatasetSize){ 
	double timeToSort;
	clock_t startSort, endSort;
	int **datasets;
	
	Unit *structUnit;

	cout << "Data set has been randomly generated from " << startDatasetSize << " multiplying by ";
	cout << multiplyDatasetSize << " over " << numDatasets << " datasets." << endl;
	system("PAUSE");
	
	int *testDataset;
	
	cout << "EXPONENTIAL" << endl;
	cout << "S#\tArrSize\t\tSelSort\t\tBubSort\t\tInsSort\t\tMerSort\t\tQuiSort\t\tAltQSrt\t\tHeapSort\t\tRadSort\t\tRevQSrt" << endl;
	for(int dataset = startDatasetSize; dataset < numDatasets; dataset++){	
		int numExpData = pow(multiplyDatasetSize, dataset);
		
		//SelectionSort
		testDataset = generateUnsortedInts(numExpData);
		//quickSort(testDataset, 0, numExpData-1);
		startSort = clock();
		selectionSort(testDataset, numExpData);
		endSort = clock();
		timeToSort = (double)(endSort - startSort)/CLOCKS_PER_SEC;
		free(testDataset);
	
		cout << dataset+1-startDatasetSize << "\t" << setw(8) << left << numExpData;
		cout << "\t" << timeToSort;
		
		//BubbleSort
		testDataset = generateUnsortedInts(numExpData);
		//quickSort(testDataset, 0, numExpData-1);
		startSort = clock();
		bubbleSort(testDataset, numExpData);
		endSort = clock();
		timeToSort = (double)(endSort - startSort)/CLOCKS_PER_SEC;
		free(testDataset);
		
		cout << "\t\t" << timeToSort;
	
		//InsertionSort
		testDataset = generateUnsortedInts(numExpData);
		//quickSort(testDataset, 0, numExpData-1);
		startSort = clock();
		insertionSort(testDataset, numExpData);
		endSort = clock();
		timeToSort = (double)(endSort - startSort)/CLOCKS_PER_SEC;
		free(testDataset);
		
		cout << "\t\t" << timeToSort;
		
		//MergeSort
		testDataset = generateUnsortedInts(numExpData);
		//quickSort(testDataset, 0, numExpData-1);
		startSort = clock();
		modMergeSort(testDataset, 0, numExpData-1);
		endSort = clock();
		timeToSort = (double)(endSort - startSort)/CLOCKS_PER_SEC;
		free(testDataset);
		
		cout << "\t\t" << timeToSort;
	
		//QuickSort
		testDataset = generateUnsortedInts(numExpData);
		//quickSort(testDataset, 0, numExpData-1);
		startSort = clock();
		altQuicksort(testDataset, 0, numExpData-1);
		endSort = clock();
		timeToSort = (double)(endSort - startSort)/CLOCKS_PER_SEC;
		free(testDataset);
		
		cout << "\t\t" << timeToSort;
		
		//AltQuickSort
		testDataset = generateUnsortedInts(numExpData);
		//quickSort(testDataset, 0, numExpData-1);
		startSort = clock();
		altQuicksort(testDataset, 0, numExpData-1);
		endSort = clock();
		timeToSort = (double)(endSort - startSort)/CLOCKS_PER_SEC;
		free(testDataset);
		
		cout << "\t\t" << timeToSort;
		
		//HeapSort
		testDataset = generateUnsortedInts(numExpData);
		//quickSort(testDataset, 0, numExpData-1);
		startSort = clock();
		heapSort(testDataset, numExpData);
		endSort = clock();
		timeToSort = (double)(endSort - startSort)/ double(CLOCKS_PER_SEC);
		free(testDataset);
		
		cout << "\t\t" << timeToSort;
		
		//RadixSort
		testDataset = generateUnsortedInts(numExpData);
		//quickSort(testDataset, 0, numExpData-1);
		startSort = clock();
		radixSort(testDataset, numExpData);
		endSort = clock();
		timeToSort = (double)(endSort - startSort)/CLOCKS_PER_SEC;
		free(testDataset);

		cout << "\t\t" << timeToSort;

		//Rev QuickSort
		testDataset = generateUnsortedInts(numExpData);
		altQuicksort(testDataset, 0, numExpData-1);
		reverseData(testDataset, numExpData);
		startSort = clock();
		altQuicksort(testDataset, 0, numExpData-1);
		endSort = clock();
		timeToSort = (double)(endSort - startSort)/CLOCKS_PER_SEC;
		free(testDataset);
		cout << "\t\t" << timeToSort;

		cout << endl;
	}
}

void linearAnalysis(int numDatasets, int startDatasetSize, int incrementDatasetSize){ 
	double timeToSort;
	clock_t startSort, endSort;
	int **datasets;
	
	Unit *structUnit;
	
	bool SS, BS, IS, MS, QS, HS, RS, MMS, QSRev, QSRand, RQSRev, RQSRand;
	SS = BS = IS = MS = QS = HS = RS = MMS = QSRev = QSRand = RQSRev = RQSRand = true;
	
	cout << "Data set has been randomly generated from " << startDatasetSize << " incrementing by ";
	cout << incrementDatasetSize << " over " << numDatasets << " datasets." << endl;
	
	int *testDataset;
	
	cout << "LINEAR" << endl;
	cout << "S#\tArrSize\t\tSelSort\t\tBubSort\t\tInsSort\t\tMerSort\t\tModMSrt\t\tHeapSort\tRadSort\t\tQuiSrt\t\tRevQSort\tRandRQSrt\tRevRQS" << endl;
	
	for(int dataset = startDatasetSize; dataset < numDatasets; dataset++){	
		int numData = incrementDatasetSize * (dataset + 1);
		
		cout << dataset+1 << "\t" << setw(8) << left << numData;
		
		//SelectionSort
		if(SS){
			testDataset = generateUnsortedInts(numData);
			//quickSort(testDataset, 0, numData-1);
			startSort = clock();
			selectionSort(testDataset, numData);
			endSort = clock();
			timeToSort = (double)(endSort - startSort)/CLOCKS_PER_SEC;
			free(testDataset);
			
			cout << "\t" << timeToSort;
			
			if(timeToSort > 180)
				SS = false;
		} else {
			cout << "\t" << "-----";
		}
		
		//BubbleSort
		if(BS){
			testDataset = generateUnsortedInts(numData);
			//quickSort(testDataset, 0, numData-1);
			startSort = clock();
			bubbleSort(testDataset, numData);
			endSort = clock();
			timeToSort = (double)(endSort - startSort)/CLOCKS_PER_SEC;
			free(testDataset);
			
			cout << "\t\t" << timeToSort;
			if(timeToSort > 180)
				BS = false;
		} else {
			cout << "\t\t" << "-----";
		}
	
		//InsertionSort
		if(IS){
			testDataset = generateUnsortedInts(numData);
			//quickSort(testDataset, 0, numData-1);
			startSort = clock();
			insertionSort(testDataset, numData);
			endSort = clock();
			timeToSort = (double)(endSort - startSort)/CLOCKS_PER_SEC;
			free(testDataset);
			
			cout << "\t\t" << timeToSort;
			if(timeToSort > 180)
				IS = false;
		} else {
			cout << "\t\t" << "-----";
		}
		
		
		//MergeSort
		if(MS){
			testDataset = generateUnsortedInts(numData);
			//quickSort(testDataset, 0, numData-1);
			startSort = clock();
			mergeSort(testDataset, 0, numData-1);
			endSort = clock();
			timeToSort = (double)(endSort - startSort)/CLOCKS_PER_SEC;
			free(testDataset);
			
			cout << "\t\t" << timeToSort;
			if(timeToSort > 180)
				MS = false;
		} else {
			cout << "\t\t" << "-----";
		}
		
		//Modified MergeSort
		if(MMS){
			testDataset = generateUnsortedInts(numData);
			//quickSort(testDataset, 0, numData-1);
			startSort = clock();
			modMergeSort(testDataset, 0, numData-1);
			endSort = clock();
			timeToSort = (double)(endSort - startSort)/CLOCKS_PER_SEC;
			free(testDataset);
			
			cout << "\t\t" << timeToSort;
			if(timeToSort > 180)
				MMS = false;
		} else {
			cout << "\t\t" << "-----";
		}

		//HeapSort
		if(HS){
			testDataset = generateUnsortedInts(numData);
			//quickSort(testDataset, 0, numData-1);
			startSort = clock();
			heapSort(testDataset, numData);
			endSort = clock();
			timeToSort = (double)(endSort - startSort)/ double(CLOCKS_PER_SEC);
			free(testDataset);
			
			cout << "\t\t" << timeToSort;
			if(timeToSort > 180)
				HS = false;
		} else {
			cout << "\t\t" << "-----";
		}
		
		//RadixSort
		if(RS){
			testDataset = generateUnsortedInts(numData);
			//quickSort(testDataset, 0, numData-1);
			startSort = clock();
			radixSort(testDataset, numData);
			endSort = clock();
			timeToSort = (double)(endSort - startSort)/CLOCKS_PER_SEC;
			free(testDataset);
			
			cout << "\t\t" << timeToSort;
			if(timeToSort > 180)
					RS = false;
		} else {
			cout << "\t\t" << "-----";
		}
		
		//Normal QuickSort
		if(QS){
			testDataset = generateUnsortedInts(numData);
			//quickSort(testDataset, 0, numData-1);
			startSort = clock();
			altQuicksort(testDataset, 0, numData-1);
			endSort = clock();
			timeToSort = (double)(endSort - startSort)/CLOCKS_PER_SEC;
			free(testDataset);
			
			cout << "\t\t" << timeToSort;
			if(timeToSort > 180)
					QS = false;
		} else {
			cout << "\t\t" << "-----";
		}
		
		//Reversed Data, Normal Quicksort
		if(QSRev){
			testDataset = generateUnsortedInts(numData);
			altQuicksort(testDataset, 0, numData-1);
			reverseData(testDataset, numData);
			startSort = clock();
			altQuicksort(testDataset, 0, numData-1);
			endSort = clock();
			timeToSort = (double)(endSort - startSort)/CLOCKS_PER_SEC;
			free(testDataset);
			
			cout << "\t\t" << timeToSort;
			if(timeToSort > 180)
				QSRev = false;
		} else {
			cout << "\t\t" << "-----";
		}
		
		// Randomized Data, Randomized Quicksort
		if(RQSRand){
			testDataset = generateUnsortedInts(numData);
			//altQuicksort(testDataset, 0, numData-1);
			//reverseData(testDataset, numData);
			startSort = clock();
			opquickSort(testDataset, 0, numData-1);
			endSort = clock();
			timeToSort = (double)(endSort - startSort)/CLOCKS_PER_SEC;
			free(testDataset);

			cout << "\t\t" << timeToSort;
			if(timeToSort > 180)
				RQSRand = false;
		} else {
			cout << "\t\t" << "-----";
		}
		
		// Reversed Data, Randomized Quicksort
		if(RQSRev){
			testDataset = generateUnsortedInts(numData);
			altQuicksort(testDataset, 0, numData-1);
			reverseData(testDataset, numData);
			startSort = clock();
			opquickSort(testDataset, 0, numData-1);
			endSort = clock();
			timeToSort = (double)(endSort - startSort)/CLOCKS_PER_SEC;
			free(testDataset);
			
		
			cout << "\t\t" << setw(5) << left << timeToSort << endl;
			if(timeToSort > 180)
				RQSRev = false;
		} else {
			cout << "\t\t" << "-----";
		}
	
	}
}

void structSortAnalysis(int numDatasets, int startDatasetSize, int incrementDatasetSize){
	double timeToSort;
	clock_t startSort, endSort;
	int **datasets;
	
	Unit *structUnit;
	int *testDataset;
	
	
	bool SS, BS, IS, MS, QS, HS, RS, MMS;
	SS = BS = IS = MS = QS = HS = RS = MMS = true;
	
	cout << "Data set has been randomly generated from " << incrementDatasetSize << " incrementing by ";
	cout << incrementDatasetSize << " over " << numDatasets << " datasets." << endl;

	cout << "STRUCT LINEAR" << endl;
	cout << "S#\tArrSize\t\tInsSort\t\tMerSort\t\tQuiSort" << endl;
	
	for(int dataset = startDatasetSize; dataset < numDatasets; dataset++){	
		int numData = incrementDatasetSize * (dataset + 1);
		
		cout << dataset+1 << "\t" << setw(8) << left << numData;

		//Structure Insertion Sort
		structUnit = generateStructData(numData);
		
		startSort = clock();
		sinsertionSort(structUnit, numData);
		endSort = clock();
		timeToSort = (double)(endSort - startSort)/CLOCKS_PER_SEC;
		free(structUnit);
		cout << "\t" << timeToSort;	
		
		//Structure Merge Sort
		structUnit = generateStructData(numData);
		startSort = clock();
		smergeSort(structUnit, 0, numData-1);
		endSort = clock();
		timeToSort = (double)(endSort - startSort)/CLOCKS_PER_SEC;
		free(structUnit);
		cout << "\t\t" << timeToSort;
		
		//Structure Quick Sort
		structUnit = generateStructData(numData);
		startSort = clock();
		squickSort(structUnit, 0, numData-1);
		endSort = clock();
		timeToSort = (double)(endSort - startSort)/CLOCKS_PER_SEC;
		free(structUnit);
		cout << "\t\t" << timeToSort;
		
		cout << endl;
	}

}

int **generateDataset(int increment, int n){
	int **datasets = (int **)calloc(n, sizeof(int *));
	
	for(int i = 0; i < n; i++)
		datasets[i] = generateUnsortedInts(increment * (i+1));
		
	
	return datasets;
}

Unit *generateStructData(int n){
	mt19937 gen(2611);
	uniform_int_distribution<> dis(1, 1000000000);
	
	Unit *mainData = (Unit *)malloc(n* sizeof(data));
	for(int i = 0; i < n; i++){
		mainData[i].key = dis(gen);
		for(int j = 0; j < 500; j++)
			mainData[i].word[j] = 'a';
	}

	return mainData;
}

int **generateExpDataset(int increment, int mult, int n){
	int **datasets = (int **)calloc(n, sizeof(int *));
	for(int i = 0; i < n; i++)
		datasets[i] = generateUnsortedInts(pow(mult, i) * increment);
		
	return datasets;
}

int *generateUnsortedInts(int n){
	mt19937 gen(2611);
	uniform_int_distribution<> dis(1, 1000000000);
	
	int *newArray = (int *)malloc(n * sizeof(long int));
	for(int i = 0; i < n; i++)
		newArray[i] = dis(gen);

	return newArray;
}


void releaseMemory(int **datasets, int n){
	for(int i = 0; i < n; i++)
		free(datasets[i]);

}

void reverseData(int A[], int n){
	int data;
	
	for(int i = n-1; i >= 0; i--){
		data = A[i];
		A[i] = A[n-i-1];
		A[n-i-1] = data;
	}
}

