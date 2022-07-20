#include <math.h>
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
        for(int k=0;k<1000000;k++);
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int main()
{
	int i, n;
    clock_t start, end;
    printf("ENTER ARRAY SIZE =");
    scanf("%d", &n);
    int arr[150000];
    printf("ENTER ARRAY ELEMENTS = ");
    for (int j = 0; j < n; j++)
    {
        arr[j] = rand()%10000;
    }
    for (i = 0; i < n; i++)
        printf(" %d", arr[i]);
    printf("\n");
    start = clock();
    insertionSort(arr, n);
    
    end = clock();

    printf("\nSORTED ELEMNETS = ");
    for (i = 0; i < n; i++)
        printf(" %d", arr[i]);
    printf("\n TIME TAKEN TO SORT %d NUMBERS IS %f SECS", n, (((double)(end - start)) / CLOCKS_PER_SEC));
    return 0;
}
