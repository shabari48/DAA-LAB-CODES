#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int arr[],int l,int h);
void swap(int *x,int *y);
void quicksort(int arr[],int l,int h);
void printArray(int arr[], int size);

int main(){
		
	FILE *fp;
	int x,n=0,i=0;
	clock_t start,end;
	double total;
	
	fp=fopen("sortin.txt","r");
	while(!feof(fp)){
		fscanf(fp,"%d",&x);
		n++;
	}
	
	printf("\tQUICK SORT\t\nThe number of elements are %d\n",n);
	
	int ar[n];
	
	rewind(fp);
	
	while(!feof(fp)){
	fscanf(fp,"%d ",&ar[i]);
		i++;
	}
		
	fclose(fp); 	  
   		
    start=clock();	  
	quicksort(ar,0,n);
    end=clock();
   
 	printf("\n\nSorted elements are\n");
  	printArray(ar,n);
     	  
    total=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\n\nThe time taken for quick sort = %f\n",total);
   
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}


void swap(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

int partition(int arr[],int l,int h){
	int pivot=arr[l];
	int i=l,j=h;

	while(i<j){
		do{
			i++;
		}while(arr[i]<=pivot);
		
		do{
			j--;
		}while(arr[j]>pivot);
		
		if(i<j)
		  swap(&arr[i],&arr[j]);
	}
	swap(&arr[l],&arr[j]);
	
	return j;
	
	}
	
void quicksort(int arr[],int l,int h){
	if(l<h){
		int j=partition(arr,l,h);
		quicksort(arr,l,j);
		quicksort(arr,j+1,h);
	}
}