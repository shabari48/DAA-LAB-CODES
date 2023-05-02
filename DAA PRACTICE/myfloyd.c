#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b)
{
    int x = a < b ? a : b;
    return x;
}
int main()
{
    int vertices, edges, p;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    int d[100][100];
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INT_MAX;
        }
    }
    int source, sink, weight;
    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge %d", i + 1);
        printf("Enter the source: ");
        scanf("%d", &source);
        printf("Enter the sink: ");
        scanf("%d", &sink);
        printf("Enter the weight: ");
        scanf("%d", &weight);
        d[source][sink] = weight;
    }

    printf("FLOYD WARSSHALL");
    for (int k = 0; k < vertices; k++)
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (d[i][k] != INT_MAX && d[k][j] != INT_MAX)
                {
                    p = min(d[i][j], d[i][k] + d[k][j]);
                    d[i][j] = p;
                }
            }
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        printf("\n");
        for (int j = 0; j < vertices; j++)
        {

            printf("%d ", d[i][j]);
        }
    }
}