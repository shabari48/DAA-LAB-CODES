#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
int vertices;
int min(int a, int b) 
{
return a < b ? a : b;
}

bool dfs(int rgraph[10][10], int source, int sink, bool visited[], int parent[]) 
{
	visited[source] = true;
	if (source == sink) 
		{
			return true;
		}
	for (int v = 0; v < vertices; v++) 
	{
		if (!visited[v] && rgraph[source][v] > 0)
			{
			parent[v] = source;
			if (dfs(rgraph, v, sink, visited, parent)) 
				{
					return true;
				}
		}
	}
	return false;
}

int fordfulkerson(int graph[10][10], int source, int sink) 
{
	int rgraph[10][10];
	for (int i = 0; i < vertices; i++) 
	{
		for (int j = 0; j < vertices; j++)
		{
			rgraph[i][j] = graph[i][j];
		}
	}
	
	int parent[vertices];
	int maxflow = 0;
	while (true) 
	{
		bool visited[vertices];
		for (int i = 0; i < vertices; i++) 
			{
			visited[i] = false;
			}
		if (!dfs(rgraph, source, sink, visited, parent)) 
			{
			break;
			}
		int pathflow = INT_MAX;
		for (int v = sink; v != source; v = parent[v])
			{
			int u = parent[v];
			pathflow = min(pathflow, rgraph[u][v]);
			}
			
		for (int v = sink; v != source; v = parent[v]) 
			{
			int u = parent[v];
			rgraph[u][v] -= pathflow;
			rgraph[v][u] += pathflow;
			}
			
		maxflow += pathflow;
	}
	return maxflow;
}

void main() 
{
int v,e,src,dest,weight,source,sink;
printf("\nEnter the number of vertices:");
scanf("%d",&vertices);
printf("\nEnter the number of edges:");
scanf("%d",&e);
int graph[10][10]={0};

for(int i=0;i<e;i++)
{
	printf("\nEnter the source,destination and weight for an edge:\n");
	scanf("%d",&src);
	scanf("%d",&dest);
	scanf("%d",&weight);
	graph[src][dest]=weight;
}
printf("Enter the source of the graph:");
scanf("%d",&source);
printf("Enter the sink of the graph:");
scanf("%d",&sink);
printf("Maximum flow: %d\n", fordfulkerson(graph,source,sink));
}