#include<stdio.h>
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
    printf(" \n %d replaced with %d \n",*a,*b);
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int part = partition(arr, low, high);
        quickSort(arr, low, part - 1);
        quickSort(arr, part + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
}
int main()
{
    int n;
	printf("Enter size of array");
	scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
    	printf("\n Enter %d element :",i);
    	scanf("%d",&arr[i]);
    }
	printf("\n Unsorted array: \n");
	printArray(arr, n);
    quickSort(arr,0, n-1);
    printf("\n Sorted array: \n");
    printArray(arr, n);
    return 0;
}
