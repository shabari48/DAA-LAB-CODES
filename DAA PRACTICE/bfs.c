#include<stdlib.h>
#include<stdio.h>
int queue[50],front=-1,rear=-1;
int n;

void enqueue(int x){
	rear++;
	queue[rear]=x;	
}

int dequeue(){
	int x=queue[++front];
	return x;
}
int isEmpty(){
	if(front==rear)
		return 1;
	return 0;
}

int main(){
	int i,j,s;
    printf("Enter the no of vetices:");
    scanf("%d",&n);
    int visited[n],parent[n],a[20][20];
    printf("Enter the matrix representation");
    for(i=0;i<n;i++)
     {
       for( j=0;j<n;j++)
        {
           printf("(%d,%d)",i,j);
           scanf("%d",&a[i][j]);
         }
       visited[i]=0;
       parent[i]=-1;
     }
    printf("Enter the source vertex:");
    scanf("%d",&s);
    printf("%d",s);
    visited[s]=1;
    enqueue(s);
    while(!isEmpty()){
    	int v=dequeue();
    	for(int t=0;t<n;t++){
    			if(a[v][t]==1&&visited[t]==0){
    				printf("%d",t);
    				parent[t]=v;
    				visited[t]=1;
    				enqueue(t);	
				}
		}
    
	}
}