#include<stdlib.h>
#include<stdio.h>
#define INF 9999
int n,cost[10][10],selected[20];


int main(){
int min,a,b;
int i;
int mincost=0;
printf("Enter the no of vetices:");
scanf("%d",&n);
printf("Enter the cost matrix representation:");
    for(int i=0;i<n;i++)
     {
       for(int j=0;j<n;j++)
        {
           printf("(%d,%d)",i,j);
           scanf("%d",&cost[i][j]);
           if(cost[i][j]==0)
              cost[i][j]=INF;
         }
     }
     
    for(int i=0;i<n;i++)
     {
       for(int j=0;j<n;j++)
        {
           if(cost[i][j]==0)
              cost[i][j]=INF;
         }
     }
	
	for(int i=0;i<n;i++)
       selected[i]=0;
       
  selected[0]=1;
  
  int edgecount=0;
  while(edgecount<n-1)
  {
  	min=INF,a=-1,b=-1;
  	for(int i=0;i<n;i++){
  		if(selected[i]){
  		for(int j=0;j<n;j++){
  			if(!selected[j]&&cost[i][j]<min){
  				min=cost[i][j];
  				a=i;
  				b=j;
			  }
		  }
	  }
}
	selected[b]=1;
	printf("\nEdge %d:(%d-%d) Cost:%d",edgecount++,a,b,min);
	mincost+=min;
  	
  }
  printf("\nTotal Cost=%d",mincost);
     

}