#include <iostream>
#include "SortAlgorithms.h"
   using namespace std;

void displayArray (int A[], int lengthA) {

	int i;
	
	for (i=0; i<lengthA; i++)
		cout << A[i] << " ";
		
	cout << endl;
}


void selectionSort (int A[], int lengthA) {

    int i, j, min, temp;  
   
    for (i=0; i<lengthA-1; i++) {  
        min = i;  
        for (j = i+1; j<lengthA; j++) { 
        	if (A[j] < A[min])  
            	min = j;  
        }

		temp = A[i];
		A[i] = A[min];
		A[min] = temp;
    }  
}  


void bubbleSort (int A[], int lengthA) {

    int i, j, temp; 
    bool swapped;
    
	for (i=0; i<lengthA-1; i++) {
	   swapped = false;
	   for (j=0; j<lengthA-i-1; j++) {
	      if (A[j] > A[j+1]) {
	         temp = A[j];
	         A[j] = A[j+1];
	         A[j+1] = temp;
	         swapped = true;
	      }
	   }
	   if (!swapped)
	   		break;
	}
}



void insertInPlace (int A[], int n, int newElement) {

	int k = n-1;

	while (k >= 0 && newElement < A[k]) {
		A[k+1] = A[k];
		k--;
	}

	A[k+1] = newElement;
}



void insertionSort (int A[], int lengthA) {
	
	int i;
	
	for (i=1; i<lengthA; i++)
		insertInPlace (A, i, A[i]);
		
}



int merge (int A[], int p, int q, int r) {
	int n1, n2;
	//int b[1000], c[1000];
	
	static int * b = new int [100000000];
	static int * c = new int [100000000];
	
	n1 = q - p + 1;
	n2 = r - q;
	
	for (int k=0; k<n1; k++)
		b[k] = A[k+p];

	b[n1] = INT_MAX; 
	
	for (int k=0; k<n2; k++)
		c[k] = A[q+k+1];		
	
	c[n2] = INT_MAX;
	
	int i, j;
	
	i = 0;
	j = 0;
	
	for (int k=p; k<=r; k++) {
		if (b[i] < c[j]) {
			A[k] = b[i];
			i++;
		}
		else {
			A[k] = c[j];
			j++;
		}
	}
	
	//delete b;
	//delete c;
}	



void mergeSort (int A[], int start, int end) {
	int mid;
	
	if (start < end) {
		mid = (start + end) / 2;
		mergeSort (A, start, mid);
		mergeSort (A, mid+1, end);
		merge (A, start, mid, end);
	}
	
}



int partition (int A[], int p, int r) {
	
	int x, i, j;
	int temp;
	
	x = A[r];	
	i = p - 1;
	
	for (j=p; j<=r-1; j=j+1) {
		if (A[j] <= x) {
			i = i + 1;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	
	temp = A[i+1];
	A[i+1] = A[r];
	A[r] = temp;

	return (i+1);
}

	

void quickSort (int A[], int p, int r) {
	int q;
	
	if (p < r) {
		q = partition (A, p, r);
		quickSort (A, p, q-1);
		quickSort (A, q+1, r);
	}
}
