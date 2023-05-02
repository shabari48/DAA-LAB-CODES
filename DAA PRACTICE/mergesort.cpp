#include <stdio.h>
#include <stdlib.h>

void merge(int arr[10], int p, int q, int r)
{
	int n1 = q + 1 - p;
	int n2 = r - q;

	int L[n1], M[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (int i = 0; i < n1; i++)
		M[i] = arr[q + 1 + i];

	int i, j, k;
	i = 0, j = 0, k = p;

	while (i < n1 && j < n2)
	{
		if (L[i] <= M[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = M[j];
			j++;
		}

		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	if (j < n2)
	{
		arr[k] = M[j];
		j++;
		k++;
	}
}

void mergesort(int arr[10], int l, int h)
{
	if (l < h)
	{
		int m = (l + h) / 2;
		mergesort(arr, l, m);
		mergesort(arr, m + 1, h);
		merge(arr, l, m, h);
	}
}

int main()
{
	int arr[10] = {3, 35, 88, 39, 6, 355, 24, 256, 156, 9};

	mergesort(arr, 0, 10);

	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
}