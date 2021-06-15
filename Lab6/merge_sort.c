#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void generateArray(int arr[10], int n)
{
	for(int i = 0; i<n; i++)
		arr[i] = (rand()%10000);
}
void print(int *arr, int n)
{
	printf("\nThe elements in the array are:\n");
	for(int i = 0; i<n; i++)
		printf("%d\t", arr[i]);
}


// int merge_sort(int* arr, int l, int n)
// {
//     if (l==n)
//         return arr[l];
//     int mid = (int)(l+n)/2;
//     int midc = mid;
//     if (n%2 != 0)
//         midc -= 1;
//     int *lower = merge_sort(arr, l, mid);
//     int *upper = merge_sort(arr, mid+1, n);
//     int i = 0, j = mid+1, k = 0;
//     while (i < mid && j < n)
//     {
//         if(lower[i]<=upper[j])
//         {
//             arr[k] = lower[i];
//             k ++;
//             i ++;
//         }
//         else
//         {
//             arr[k] = upper[j];
//             k ++;
//             j++;
//         }
//     }
//     if (i > j-mid)
//     {
//         while(j < n)
//         {
//             arr[k] = upper[j];
//             k += 1;
//             j += 1;
//         }
//     }
//     else
//     {
//         while(i < mid)
//         {
//             arr[k] = lower[i];
//             k += 1;
//             i += 1;
//         }
//     }
//     return arr;
// }

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
  
    int L[n1], R[n2];
  
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
  
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
  
        merge(arr, l, m, r);
    }
}


int main()
{
	int *arr, ch=10, n;
	clock_t start_l, start_b, end_l, end_b;
	srand(time(0));
	while(ch!=3)
	{
		printf("\n\n\n\t1]Merge Sort\n\t2]Exit\nEnter Choice:\t");
		scanf("%d", &ch);
		if(ch==2)
			break;
		printf("\nEnter the size of Array:\t");
		scanf("%d", &n);
		generateArray(arr, n);
		print(arr, n);
		switch(ch)
		{
			case 1:	start_l = clock();
					mergeSort(arr, 0, n-1);
                    end_l = clock();
					break;
			default: printf("\nEnter Valid Choice\n\n\n");
		}
    printf("\n\nThe sorted array is:");
    print(arr, n);
	}

	printf("\nTime taken for Merge Sort: %Lf", (long double)(end_l - start_l)/CLOCKS_PER_SEC);
}
