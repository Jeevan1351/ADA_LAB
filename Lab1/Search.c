#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void generateArray(int arr[10], int n)
{
	for(int i = 0; i<n; i++)
		arr[i] = (rand()%100);
}
void print(int *arr, int n)
{
	printf("\nThe elements in the array are:\n");
	for(int i = 0; i<n; i++)
		printf("%d\t", arr[i]);
}

void LinearSearch(int* arr, int n)
{
	int e;
	printf("\nEnter the element to be searched:\t");
	scanf("%d", &e);
	for(int i = 0; i<n; i++)
	{
		if(arr[i] == e)
		{
			printf("\nElement found at index: %d", i);
			return;
		}
	}
	printf("\nElement not found!");
}

void Sort(int* arr, int n)
{
	for(int i = 0; i<n; i++)
	{
		for(int j = i+1; j<n; j++)
		{
			if(arr[i]>arr[j])
			{
				int t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}
}
void BinarySearch(int* arr, int n)
{
	int e;
	printf("\nEnter the element to be searched:\t");
	scanf("%d", &e);
	int low = 0, high = n-1;
	int mid = (int)((high-low)/2);
	while(1)
	{
		if(e==arr[mid])
		{
			printf("\nElement Found at index:%d", mid);
			return;
		}
		else if(e>arr[mid])
		{
			low = mid;
			mid =mid + (int)((high - low)/2);
		}
		else
		{
			high = mid;
			mid = (int)((high-low)/2);
		}
		if(low == high)
			break;
	}
	printf("\nElement Not Found!");
}


int main()
{
	int *arr, ch=10, n;
	srand(time(0));
	while(ch!=3)
	{
		printf("\n\n\n\t1]Linear Search\n\t2]Binary Search\n\t3]Exit\nEnter Choice:\t");
		scanf("%d", &ch);
		if(ch==3)
			break;
		printf("\nEnter the size of Array:\t");
		scanf("%d", &n);
		generateArray(arr, n);
		print(arr, n);
		switch(ch)
		{
			case 1: LinearSearch(arr, n);
					break;
			case 2: Sort(arr, n);
					printf("\n\nSorted array is");
					print(arr, n);
					BinarySearch(arr, n);
					break;
			default: printf("\nEnter Valid Choice\n\n\n");
		}
	}
}
