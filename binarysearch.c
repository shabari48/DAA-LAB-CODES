#include<stdio.h>
#include<stdlib.h>
#include<time.h>




int n=0,x,arr[100000];


void linearsearch(){
	int show=-1; 

	 for(int i=0;i<n;i++){
    	if(arr[i]==x)
    	 {
    	 	show=0;
    	 	printf("\nElement found \n");
    	 	return;
		 }
	}

	if(show==-1){
	  printf("\nElement not found\n");
}
}

int binarysearch(int a[],int key,int low,int high){

	if(low>high)
		return -1;

	else {
	 int mid=(low +high)/2;
	 
	if(key==arr[mid])
		 return mid;

	else if (x>arr[mid])
			return binarysearch(a, key,mid+1,high);
	else 

		return binarysearch(a, key,low,mid-1);
				
	}
	
}
void swap(int* x,int* y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

void bubblesort(){
	int min;
	for(int i=0;i<n;i++){
		min=i;
		for(int j=i+1;j<n;j++){
			if(arr[min]>arr[j])
			  min=j;
			   
		}
		swap(&arr[i],&arr[min]);
	}
		
		 
}

int main(){
	
	FILE *fp;
	int i=0;
	int result;
	clock_t lstart,lend,bstart,bend;
	double ltotal,btotal;
	
	fp=fopen("searchinput.txt","r");
	while(!feof(fp)){
		fscanf(fp,"%d",&arr[i]);
		n++;
		i++;
	}
	fclose(fp);
	

    
    printf("\nEnter the element to search: ");
    scanf("%d",&x);
    
    lstart=clock();
    linearsearch();
    lend =clock();
    
    bubblesort();
    
    bstart=clock();
    result= binarysearch(arr,x,0,n);
   bend =clock();
   
   if(result!=-1)
     printf("\nElement found \n");
     
  else 
  printf("\nElement not found\n");
  
  ltotal=(double)(lend-lstart)/CLOCKS_PER_SEC;
  btotal=(double)(bend-bstart)/CLOCKS_PER_SEC;
  
   printf("\nMilli seconds taken in linear search is %f",ltotal);
   printf("\nMilli seconds taken in binarysearch %f",btotal);
   
}
    