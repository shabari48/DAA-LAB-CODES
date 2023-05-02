#include <stdlib.h>
#include <stdio.h>
#define INF 9999
int n, cost[10][10], parent[20];

int find(int i)
{
   while (parent[i] != i)
      i = parent[i];

   return i;
}

void Union(int i, int j)
{
   int a = find(i);
   int b = find(j);
   parent[a] = b;
}

int main()
{
   int min, a, b;
   int mincost = 0;
   printf("Enter the no of vertices:");
   scanf("%d", &n);
   printf("Enter the cost matrix representation");
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         printf("(%d,%d)", i, j);
         scanf("%d", &cost[i][j]);
         if (cost[i][j] == 0)
            cost[i][j] = INF;
      }
   }

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (cost[i][j] == 0)
            cost[i][j] = INF;
      }
   }

   for (int i = 0; i < n; i++)
      parent[i] = i;

   int edgecount = 0;
   while (edgecount < n - 1)
   {
      min = INF, a = -1, b = -1;
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
         {
            if (find(i) != find(j) && cost[i][j] < min)
            {
               min = cost[i][j];
               a = i;
               b = j;
            }
         }
      }
      Union(a, b);
      printf("\nEdge %d:(%d-%d) Cost:%d", edgecount++, a, b, min);
      mincost += min;
   }
   printf("\nTotal Cost=%d", mincost);
}