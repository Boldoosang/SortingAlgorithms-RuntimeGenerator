#include <iostream>
#include "MaxHeap.h"
   using namespace std;

int parent(int i) {
	return (i/2);
}



int leftChild(int i) {
	return (2 * i);
}



int rightChild (int i) {
	return (2 * i) + 1;
}



void maxHeapify (int A[], int heapSize, int i) {
	int left, right, largest;
	
	left = leftChild(i);
	right = rightChild(i);
	
	if (left <= heapSize && A[left] > A[i]) 
		largest = left;
	else
		largest = i;
		
	if (right <= heapSize && A[right] > A[largest]) 
		largest = right;
		
	if (largest != i) {
		int temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		maxHeapify(A, heapSize, largest);
	}
}



void buildMaxHeap(int A[], int lengthA) {

	int heapSize, i;
	
	heapSize = lengthA;
	
	for (i = (lengthA/2); i >= 1; i = i - 1)
			maxHeapify(A, heapSize, i);
}



void displayMaxHeap (int A[], int lengthA) {
	
	int i;
	
	for (i=1; i<=lengthA; i = i + 1) 
		cout << A[i] << " ";
	
	cout << endl;
}



void heapSort (int A[], int lengthA) {
	
	int heapSize, i;
	
	heapSize = lengthA;

	buildMaxHeap(A, lengthA);
		
	for (i=lengthA; i >= 2; i = i - 1) {
		int temp = A[1];
		A[1] = A[i];
		A[i] = temp;
		heapSize = heapSize - 1;
		maxHeapify(A, heapSize, 1);
	}
}
