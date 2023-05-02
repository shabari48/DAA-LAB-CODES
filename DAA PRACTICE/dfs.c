#include <stdlib.h>
#include <stdio.h>
int post[20], pre[20], visited[10], parent[10];
int a[20][20];
int count = 0, n;

void dfs(int s)
{
	pre[s] = count++;
	printf("%d", s);
	visited[s] = 1;
	for (int i = 0; i < n; i++)
	{
		if (a[s][i] == 1 && visited[i] == 0)
		{
			parent[i] = s;
			dfs(i);
		}
	}

	post[s] = count++;
}

int main()
{
	int i, j, s;
	printf("Enter the no of vertices:");
	scanf("%d", &n);
	printf("Enter the matrix representation");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("(%d,%d)", i, j);
			scanf("%d", &a[i][j]);
		}
		visited[i] = 0;
		parent[i] = -1;
	}
	printf("Enter the source vertex:");
	scanf("%d", &s);
	dfs(s);
	for (i = 0; i < n; i++)
	{
		if (visited[i] == 0)
		{
			dfs(i);
			printf("%d", i);
		}
	}

	printf("\nEdge\tPre number\tPost Number\t   Parent\n");
	for (i = 0; i < n; i++)
		printf("%d\t\t%d\t\t%d\t\t%d\n", i, pre[i], post[i], parent[i]);
}
