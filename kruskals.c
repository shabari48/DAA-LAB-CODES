#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define V 8
#define MAX 999;
    
    int i, j, k, a, b, u, v;
	
	
    int min, mincost = 0, cost[9][9], parent[9];
    int find(int);
    int uni(int, int);
    
    int main() {
   
      


 
 for (i = 1; i <= V; i++) {
          for (j = 1; j <= V; j++) {
          	printf("Enter  cost matrix %d-%d",i,j);
          	scanf("%d",&cost[i][j]);
          }}
 
  for (i = 1; i <= V; i++) {
          for (j = 1; j <= V; j++) {
          	if(cost[i][j]==0)
          	  cost[i][j]=MAX;
          }
      }
      
//      
// for (i = 0; i < V; i++) {
//          for (j = 0; j < V; j++) {
//          printf("%d",cost[i][j]);
//          }
//      }
//      
      int  edges =1;
      
      printf("The edges of Minimum Cost Spanning Tree are\n");
      while (edges<V) {     	
        for (i = 1,min = 999; i <= V; i++) {
          for (j = 1; j <= V; j++) {
            if (cost[i][j] < min) {
              min = cost[i][j];
              a = u = i;
              b = v = j;
            }
          }
        }
        
        u = find(u);
        v = find(v);
        
        if (uni(u, v)) {
          printf("%d edge (%d,%d) =%d\n", edges+1, a+1, b+1, min);
          mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
        edges++;
      }
      printf("\n\tMinimum cost = %d\n", mincost);
      
    }
    
    
    int find(int i) {
      while (parent[i])
        i = parent[i];
      return i;
    }
    
    
    int uni(int i, int j) {
      if (i != j) {
        parent[j] = i;
        return 1;
		}}
