#include<stdio.h>
int pickIndex(int n, int picked[n], int cost[n])
{
    int mini = 0;
    int min = 999;
    for(int i = 0; i<n; i++)
    {
        if(picked[i] == 0 && cost[i] < min)
        {
            min = cost[i];
            mini = i;
        }
    }
    return mini;
}


void updateDistances(int n, int row, int index, int cost[n][n], int adj[n][n], int number[n])
{
    for(int i = 0; i<n; i++)
    {
        if(adj[index][i] != 999 && adj[index][i]+cost[row-1][index] < cost[row][i])
        {
            number[i] = number[index]+1;
            cost[row][i] = adj[index][i]+cost[row-1][index];
        }
        cost[row+1][i] = cost[row][i];
    }
}


void dijsktra(int n, int adj[n][n], int number[n])
{
    int nodes[n];
    int cost[n][n];
    for(int i =0; i<n; i++)
    {
        number[i] = 0;
        nodes[i] = 0;
        cost[i][0] = 0;
        for(int j = 1; j<n; j++)
        {
            cost[i][j] = 999;
        }
    }
    int row = 0;
    while(row < n)
    {
        int index = pickIndex(n, nodes, cost[row]);
        nodes[index] = 1;
        row ++;
        updateDistances(n, row-1, index, cost, adj, number);
    }
    for(int i = 0; i<n; i++)
    {
        printf("%d\t", cost[n-1][i]);
    }
    printf("\n");
    for(int i = 0; i<n; i++)
    {
        printf("%d\t", number[i]);
    }
}
int main()
{
    int number[5];
     int graph[5][5] = { 
                        { 0, 2, 999, 6, 999 },
                        { 2, 0, 3, 8, 5 },
                        { 999, 3, 0, 999, 7 },
                        { 6, 8, 999, 0, 9 },
                        { 999, 5, 7, 9, 0 } };
        dijsktra(5, graph, number);
}