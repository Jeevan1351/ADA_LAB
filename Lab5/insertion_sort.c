#include<stdio.h>

int* insert(int n, int* arr, int e)
{
    int sorted[n];
    // sorted[0] = arr[0];
    int i, j = 0;
   for(i = 0; i<n; i++)
    {
	if(arr[i] < e)
	{
	    sorted[j] = arr[i];
	    j++;
	}
	else
	{
	    sorted[j] = e;
	    j++;
	    break;
	}
    }

    while(i < n)
    {
	sorted[j] = arr[i];
	i++;
	j++;
    }
    for(j--; j>=0; j--)
        arr[j] = sorted[j];
}


void insertion_sort(int n, int* arr, int* sorted)
{
    sorted[0] = arr[0];
    for(int i = 0; i<n-1; i++)
    {
    	if(arr[i] > arr[i+1])
    	{
    	    insert(i+1, sorted, arr[i+1]);
    	    
    	}

    }

}



void print(int n, int * arr, int* sorted)
{
    printf("\nThe given array is:\n");
    for(int i =0; i<n; i++)
    {
	printf("%d\t", arr[i]);
    }
    printf("\nThe sorted array is :\n");
    for(int i =0; i<n; i++)
    {
	printf("%d\t", sorted[i]);
    }
}

int main()
{
    int sorted[10];
    int n;
    printf("Enter the size of the array:\t");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i<n; i++)
	scanf("%d", arr+i);
    insertion_sort(n, arr, sorted);
    print(n, arr, sorted);
}
