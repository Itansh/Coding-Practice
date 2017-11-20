#include <stdio.h>
 
void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");    
}
void swap(int* a, int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
    printf(" \n %d replaced with %d \n",*a,*b);
}
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i=0; i<n-1; i++)       
       for (j=0; j<n-i-1; j++) 
           if (arr[j]>arr[j+1])
              {
			  	swap(&arr[j], &arr[j+1]);
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
    bubbleSort(arr, n);
    printf("\n Sorted array: \n");
    printArray(arr, n);
    return 0;
}
