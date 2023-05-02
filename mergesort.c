// Merge sort in C

#include <stdio.h>
#include<time.h>


void merge(int arr[], int p, int q, int r) {

 
  int n1 = q+1 - p ;
  int n2 = r - q;//r+1-q+1

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

 
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}


void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    int m = (l + r) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}


int main() {
	
 	FILE *fp;
	int x,n=0,i=0;
	clock_t start,end;
	start=clock();
	double total;
	
	fp=fopen("sortin.txt","r");
	while(!feof(fp)){
		fscanf(fp,"%d",&x);
		n++;
	}
	
	printf("\tMERGE SORT\t\nThe number of elements are %d\n",n);
	

	int ar[n];
	
	rewind(fp);
	
	while(!feof(fp)){
	fscanf(fp,"%d ",&ar[i]);
		i++;
	}
		
	fclose(fp);

  
  mergeSort(ar, 0, n-1);
  end=clock();

  printf("\n\nSorted elements are\n");
  printArray(ar, n);
  
  total=(double)(end-start)/CLOCKS_PER_SEC;
  printf("\n\nThe time taken for merge sort = %f\n",total);
}