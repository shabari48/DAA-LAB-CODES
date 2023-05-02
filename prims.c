#include<stdio.h>
#include<stdbool.h> 

#define INF 9999999


#define V 8


int G[V][V] = {
  {0, 55, 25, 45, 0,0,0,0},
  {55, 0, 0,0,5,0,0,0},
   {25, 0, 0,0,40,0,0,0},
    {45, 0, 0,0,20,0,0,30},
{0, 5, 40,20,0,35,15,0}, 
{0, 0, 0,0,35,0,10,0}, 
{0, 0, 0,0,15,10,0,50}, 
{0, 0, 0,30,0,0,50,0}, 
 };

int main() {
  int edge=0;  

  
  int selected[V];

 
 for (int i=0;i<V;i++)
    selected[i]=0;
	  
 

 
  selected[0] = 1;

  int x;  
  int y;  
  int cost=0;
 
  printf("Edge : Weight\n");

  while (edge < V - 1) {
  
    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {  
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%d - %d : %d\n", x, y, G[x][y]);
    cost=cost+G[x][y];
    selected[y] = 1;
    edge++;
  }
  printf("\nTotal cost is %d",cost);

  return 0;
}