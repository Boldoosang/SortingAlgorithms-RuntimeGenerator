struct Unit{
	int key;
	char word[500];
};


#ifndef _SORTMETHODS_H
#define _SORTMETHODS_H

void displayArray (int **A, int n);
void selectionSort (int A[], int lengthA);
void bubbleSort (int A[], int lengthA);
void insertionSort (int A[], int lengthA);
void mergeSort (int A[], int start, int end);
void quickSort (int A[], int p, int r);
void altQuicksort(int * tab, int l, int r);
void countSort(int arr[], int n, int exp);
void radixSort(int arr[], int n);
int getMax(int arr[], int n);
void modMergeSort (int A[], int start, int end);
void swap(int* a, int* b) ;
int rPartition(int A[], int p, int r);
int modMerge (int A[], int p, int q, int r);

void sinsertInPlace (Unit A[], int n, Unit newStruct);
void sinsertionSort (Unit A[], int lengthA);
void smergeSort (Unit A[], int start, int end);
void squickSort (Unit A[], int p, int r);

int rPartition(int A[], int p, int r);
void opquickSort (int A[], int p, int r);

#endif
