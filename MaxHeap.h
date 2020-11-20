#ifndef _MAXHEAP_H
#define _MINHEAP_H

int parent (int i);
int leftChild (int i);
int rightChild (int i);
void maxHeapify (int A[], int heapSize, int i);
void buildMaxHeap (int A[], int heapSize);
void displayMaxHeap (int A[], int heapSize);
void heapSort (int A[], int lengthA);

#endif
