#include<stdlib.h>
#include<time.h>
#include <stdio.h>

void generateArray(int arr[10], int n)
{
	for(int i = 0; i<n; i++)
		arr[i] = (rand()%100);
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
	for(int i = 0; i< 32767; i++)
		for(int j = 0; j<32767; j++)
			continue;

    for (i = 0; i < n-1; i++)
    {

        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}


void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main()
{
	int n;
	clock_t start, stop;
	printf("\nEnter the number of elements:\t");
	scanf("%d", &n);
    int arr[n];
	generateArray(arr, n);
	start = clock();
    selectionSort(arr, n);
	stop = clock();
    printf("Sorted array: \n");
    printArray(arr, n);
	printf("\n\nTime : %lf\n", (double)(stop-start)/CLOCKS_PER_SEC);
    return 0;
}
