#include<stdio.h>

int graph[100][100],v,par[100],dist[100],sv,vis[100];
int min(int dist[],int vis[])
{
int min=100,i,vertex;
for(i=0;i<v;i++)
{
if(vis[i]==0 && dist[i]<min)
{
vertex=i;
 min=dist[i]; 
 }
}
return vertex;
}
void dijktra()
{
int i,d,j;
for(i=0;i<v-1;i++)
{ 
d=min(dist,vis);
vis[d]=1;
for(j=0;j<v;j++)
 {
 if(graph[d][j]!=0 && dist[j]>dist[d]+graph[d][j] && vis[j]==0)
 {
 dist[j]=dist[d]+graph[d][j];
 par[j]=d;
 }
 }
 
}
for(i=0;i<v;i++)
{
printf("%d\t ",dist[i]);
}
}
int main()
{
int i,j;
printf("enter the number of vertices:");
scanf("%d",&v);
printf("\n constructing weighted graph:\n");
for(i=0;i<v;i++)
{
for(j=0;j<v;j++)
{
 printf("%d--%d:",i,j);
scanf("%d",&graph[i][j]);
}
}
for(i=0;i<v;i++)
{
dist[i]=100;
par[i]=-1;
vis[i]=0;
}
printf("\nenter the source vertex:");
scanf("%d",&sv);
dist[sv]=0;
par[sv]=-1;
dijktra();
}