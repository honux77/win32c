#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

#define SWAP(a, b, t) ((t)=(a),(a)=(b),(b)=(t))

void BubbleSort(int arr[], int n) {
	int i, j, t;
	for (i = 0 ; i < n - 1 ; i++) {
		for (j = 0 ; j < n - i - 1 ; j++) {
			if (arr[j] > arr [j+1])
				SWAP(arr[j], arr[j+1], t);
		}
	}
}

void SelectionSort(int arr[], int n) {
	int i, j, t;
	int min_idx;
	for (i = 0 ; i < n - 1 ; i++) {
		min_idx = i;
		for (j = i + 1 ; j < n ; j++) {
			if (arr[j] < arr[min_idx])
				min_idx = j;		
		}
		SWAP(arr[min_idx], arr[i], t);		
	}
}

void InsertionSort(int arr[], int n)
{
	int i, j, key;
	for (i = 1 ; i < n ; i ++)
	{
		key = arr[i];
		for( j = i-1 ; j >= 0 ; j--)
		{
			if(arr[j] <= key)
				break;
			arr[j+1] = arr[j];			
		}
		arr[j+1]= key;
	}
}

#define SIZE 100
void (*Sort)(int [], int);
void printarr(int arr[], int n)
{
	int i;
	for (i = 0 ; i < n ; i++)
		if(((i + 1) % 20))
			printf("%3d ", arr[i]);
		else
			printf("%3d\n", arr[i]);
	printf("\n");
}

int main(void) {
	int a[SIZE];
	int i;
	Sort = InsertionSort;	
	//srand((unsigned int)time(NULL));
	for(i = 0 ; i < SIZE ; i++)
		a[i] = rand()%SIZE;
	 
	Sort(a, SIZE);
	printarr(a,SIZE);	
	return 0;
}