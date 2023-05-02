#include<stdio.h>

int i,j,course,req,ncourse,nreq,top=-1;

int visited[10],parent[10];

int matrix[10][10],transpose[10][10];

int count=0;

int stack[10];




void push(int x){
	stack[++top]=x;
}

int pop(){
    	return stack[top--];
}
	
void dfs(int i){
	printf("%d",i);
	visited[i]=1;
	for(int j=1;j<=ncourse;j++){
		if(matrix[i][j]==1&&visited[j]==0){
		    parent[j]=i;
		    dfs(j);
	}
	}
	push(i);

}

void init(){
	 printf("Enter the no of course and requirements: ");
	 scanf("%d ",&ncourse);
	scanf("%d",&nreq);
	 
	 
	 	for(i=1;i<=ncourse;i++){
	 		visited[i]=0;
	    	parent[i]=-1;
	 		for(j=1;j<=ncourse;j++){
	 			matrix[i][j]=0;
			 }
	}
	 
	for(i=1;i<=nreq;i++){
	    printf("Enter the course and its prerequistes: ");
		scanf("%d ",&course);
		scanf("%d",&req);
		matrix[course][req]=1;
	}
}


void topo(){
	printf("\n\nTOPOLOGICAL SORTED ORDER:  ");
	while(top!=-1){
		int x=pop();
		printf("%d",x);
	}
	
for(i=0;i<ncourse;i++){
	printf("\n");
	for(j=1;j<=ncourse;j++){
		printf("%d ",matrix[i][j]);

}
}
}

int main(){  
        
	init();
	
	printf("\n\tDFS TRAVERSAL\n");
	
	for(i=1;i<=ncourse;i++){
		if(visited[i]==0)
			dfs(i);
	}

	
	topo();
}
	