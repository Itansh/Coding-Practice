#include <stdio.h>
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    printf(" \n %d replaced with %d \n",*a,*b);
}
 
void printArray(int arr[], int n)
{
    for (int i=0;i<n;i++)
        printf("%d ",arr[i]);
}

void SelectionSort(int arr[], int n)
{
    int i,j,min_idx;
    for (i=0;i<n-1;i++)
    {
        // Find the minimum 
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 		printf("\n Minimum element =%d \n",arr[min_idx]);
        swap(&arr[min_idx], &arr[i]);
        printArray(arr, n);
    }
}

int main()
{
	int n;
	printf("Enter size of array :");
	scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
    	printf("\n Enter %d element :",i);
    	scanf("%d",&arr[i]);
    }
	printf("\n Unsorted array: \n");
	printArray(arr, n);
    SelectionSort(arr, n);
    printf("\n Sorted array: \n");
    printArray(arr, n);
    return 0;
}
