#include<stdio.h>

int dfs(int n, int a[n][n], int i, int j, int visited[n])
{
	for(int l = i; l<n; l++)
		for(int m = j; m<n; m++)
		{
			if (a[l][m] != 0 && visited[a[l][m]] == 0)
			{
				printf("%d", a[l][m]);
				visited[l] = 1;
				dfs(n, a, a[l][m]-1, 0, visited);
			}
		}
	return 0;
}




int main()
{
	int n;
	printf("Enter the number of nodes:\t");
	scanf("%d", &n);
	int adj[n][n];
	int v[n];
	printf("Enter the adjacency matrix:\n");
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
			scanf("%d", &adj[i][j]);
		v[i] = 0;
	}
	printf("\n%d", dfs(n, adj, 0, 0, v));
}

