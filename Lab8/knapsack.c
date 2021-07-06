#include<stdio.h>
int max(int a, int b)
{
    if(a > b)
    return a;
    return b;
}


int knapsack(int W,int n,int weights[n],int values[n])
{
    int table[W+1];
    for(int i = 0; i<=W; i++)
    {
        table[i] = 0;
    }
    for(int i = 0; i < n; i++)
    {
        for(int w=W; w>0; w--)
        {
            if(weights[i] <= w)
            {
                table[w] = max(table[w], table[w-weights[i]]+values[i]);
            }
        }
    }
    return table[W];
}

int main()
{
    int values[10];
    int weights[10];
    int n;
    printf("Enter the number of Elements:\t");
    scanf("%d", &n);
    for(int i =0; i<n; i++)
    {
        printf("Enter the weight and value of element %d:\t", i+1);
        scanf("%d %d", weights+i, values+i);
    }
    int target;
    printf("\nEnter the Capacity:\t");
    scanf("%d", &target);

    int final = knapsack(target, n, weights, values);
    printf("%d", final);
}