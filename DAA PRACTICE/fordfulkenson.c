#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
int vertices;

int min(int u, int v)
{
    int mini = u <= v ? u : v;
    return mini;
}

bool dfs(int rgraph[10][10], int source, int sink, bool visited[], int parent[])
{
    visited[source] = true;
    if (source == sink)
        return true;

    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i] && rgraph[source][i] > 0)
        {
            parent[i] = source;
            if (dfs(rgraph, i, sink, visited, parent))
                return true;
        }
    }
    return false;
}

int fordfulkenson(int graph[10][10], int source, int sink)
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
    int pathflow = INT_MAX;
    int maxflow = 0;

    while (true)
    {
        bool visited[vertices];
        for (int i = 0; i < vertices; i++)
        {
            visited[i] = false;
        }
        if (!dfs(rgraph, source, sink, visited, parent))
            break;
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            pathflow = min(pathflow, rgraph[u][v]);
        }
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            rgraph[v][u] += pathflow;
            rgraph[u][v] -= pathflow;
        }
        maxflow += pathflow;
    }

    return maxflow;
}

int main()
{
    int edges;
    int src, dest, w;
    int source, sink;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    int graph[10][10];

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; i < vertices; i++)
        {
            graph[i][j] = 0;
        }
    }

    printf("\nEnter the number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++)
    {
        printf("\nEnter edge source: ");
        scanf("%d", &src);
        printf("\nEnter edge destination: ");
        scanf("%d", &dest);
        printf("\nEnter edge weight: ");
        scanf("%d", &w);
        graph[src][dest] = w;
    }
    int result = fordfulkenson(graph, source, sink);
    printf("\nThe result is %d", result);
}
