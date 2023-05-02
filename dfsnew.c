#include<stdio.h>

int vertices;
int visited[10];

int matrix[10][10];

int pre[10],post[10],parent[10];

int count=0;

int i,j;

	
void dfs(int i){
	pre[i]=count;
	count++;
	printf("%d",i);
	visited[i]=1;
	for(int j=0;j<vertices;j++){
		if(matrix[i][j]==1&&visited[j]==0){
		
		    parent[j]=i;
		    dfs(j);
	}}
	post[i]=count;
	count++;

}


void init(){
	 printf("Enter the no of vertices: ");
	 scanf("%d",&vertices);
	 
	for(i=0;i<vertices;i++){
		visited[i]=0;
		parent[i]=-1;
		for(j=0;j<vertices;j++){
			printf("Enter the matrix connection  (%d,%d): ",i,j);
			scanf("%d",&matrix[i][j]);
		}
	}
}
	int main(){  
        
	init();
	
	printf("DFS TRAVERSAL\n");
	
	dfs(0);
	
	printf("\nEdge\tPre number\tPost Number\t   Parent\n"); 
	for(i=0;i<vertices;i++)
	   printf("%d\t\t%d\t\t%d\t\t%d\n",i,pre[i],post[i],parent[i]);
	   
		for(i=0;i<vertices;i++){
		visited[i]=0;
		parent[i]=-1;
	}
}
