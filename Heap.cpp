#include<stdio.h>
#include<process.h>
void swap(int &a,int &b)
{
	int tem;
	tem=a;
	a=b;
	b=tem;
}
void maxheapify(int arr[],int n, int idx)
{
	printf("In heapify\n");
	int largest=idx;
	int left=(2*idx)+1;
	int right=(2*idx)+2;
	if(left<n && arr[left]<arr[largest])
	{
		largest=left;
	}
	if(right<n && arr[right]<arr[largest])
	{
		largest=right;
	}
	if(largest!=idx)
	{
		printf("swapped %d <-> %d \n",arr[idx],arr[largest] );
		swap(arr[largest],arr[idx]);
		
		maxheapify(arr,n,largest);
	}

}
void maxheapsort(int arr[],int n)
{
	for(int i=(n/2)-1;i>=0;i--)
	{
		maxheapify(arr,5,i);
	}
	for(int i=n-1;i>0;i--)
	{
		swap(arr[0],arr[i]);
		maxheapify(arr,i,0);
	}
}
int main()
{
	int arr[5]={8,2,6,7,9};
	maxheapsort(arr,5);
	for(int i=0;i<5;i++)
	{
		printf("%d " , arr[i]);
	}
	return 0;
}

