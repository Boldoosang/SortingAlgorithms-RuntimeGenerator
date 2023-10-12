#include <iostream>
#include <random>
#include "SortAlgorithms.h"
   using namespace std;

void displayArray (int **A, int n) {
	for (int i = 0; i < n; i++)
		cout << i << "\t" << (*A)[i] << endl;
		
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
	
	int * b = new int [100000000];
	int * c = new int [100000000];
	
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
	
	delete(b);
	delete(c);
}

static int * b = new int [1000000000];
static int * c = new int [1000000000];
	
int modMerge (int A[], int p, int q, int r) {
	int n1, n2;
	
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

void modMergeSort (int A[], int start, int end) {
	int mid;
	
	if (start < end) {
		mid = (start + end) / 2;
		modMergeSort (A, start, mid);
		modMergeSort (A, mid+1, end);
		modMerge (A, start, mid, end);
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

int getMax(int arr[], int n) { 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
}

int rPartition(int A[], int p, int r){
	mt19937 gen(0);
	uniform_int_distribution<> dis(p, r);
	
	int i = dis(gen);
	
	int temp = A[r];
	A[r] = A[i];
	A[i] = temp;
	
	return partition(A, p, r);
}

void opquickSort (int A[], int p, int r) {
   while(p < r){
      int q = rPartition(A, p, r);
      if(q - p < r - q) {
         opquickSort(A, p, q - 1);
         p = q + 1;
      } else {
         opquickSort(A, q + 1, r);
         r = q - 1;
      }
   }
}

void altQuicksort(int * tab, int l, int r){
   while(l < r){
      int q = partition(tab, l, r);
      if(q - l < r - q) {
         altQuicksort(tab, l, q - 1);
         l = q + 1;
      } else {
         altQuicksort(tab, q + 1, r);
         r = q - 1;
      }
   }
}


// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void countSort(int arr[], int n, int exp) { 
    int * output = new int[n]; // output array 
    int i, count[10] = { 0 }; 

    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++) 
        count[(arr[i] / exp) % 10]++; 

    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 

    // Build the output array 
    for (i = n - 1; i >= 0; i--) { 
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
        count[(arr[i] / exp) % 10]--; 
    } 

    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 

// The main function to that sorts arr[] of size n using 
// Radix Sort 
void radixSort(int arr[], int n) { 
    // Find the maximum number to know number of digits 
    int m = getMax(arr, n); 

    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; m / exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
}

void sinsertInPlace (Unit A[], int n, Unit newStruct) {

	int k = n-1;

	while (k >= 0 && newStruct.key < A[k].key) {
		A[k+1] = A[k];
		k--;
	}

	A[k+1] = newStruct;
}

void sinsertionSort (Unit A[], int lengthA) {
	int i;
	
	for (i=1; i<lengthA; i++)
		sinsertInPlace (A, i, A[i]);
		
}

int smerge (Unit A[], int p, int q, int r) {
	int n1, n2;
	
	static Unit *d = (Unit *)malloc(100000000*sizeof(Unit));
	static Unit *e = (Unit *)malloc(100000000*sizeof(Unit));
	
	n1 = q - p + 1;
	n2 = r - q;
	
	for (int k=0; k<n1; k++)
		d[k] = A[k+p];
		
	d[n1].key = INT_MAX; 
	
	for (int k=0; k<n2; k++)
		e[k]= A[q+k+1];		
	
	e[n2].key= INT_MAX;
	
	int i, j;
	
	i = 0;
	j = 0;
	
	for (int k=p; k<=r; k++) {
		if (d[i].key < e[j].key) {
			A[k] = d[i];
			i++;
	}
		else {
			A[k] = e[j];
			j++;
		}
	}
	
}

void smergeSort (Unit A[], int start, int end) {
	int mid;
	
	if (start < end) {
		mid = (start + end) / 2;
		smergeSort (A, start, mid);
		smergeSort (A, mid+1, end);
		smerge (A, start, mid, end);
	}
}

int spartition (Unit A[], int p, int r) {
	
	int x, i, j;
	Unit temp;
	
	x = A[r].key;	
	i = p - 1;
	
	for (j=p; j<=r-1; j=j+1) {
		if (A[j].key <= x) {
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

void squickSort (Unit A[], int p, int r) {
	int q;

	if (p < r) {
		q = spartition (A, p, r);
		squickSort (A, p, q-1);
		squickSort (A, q+1, r);
	}
}
