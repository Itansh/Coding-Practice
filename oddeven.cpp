#include<stdio.h>
#include<stdlib.h>
#include<cuda.h>
__global__ void even(int *darr,int *n)
{
	int k=threadIdx.x;
	k=k*2;
	if(k<=n-2)
	{
		if(darr[k]>drr[k+1])
		{
			int t=darr[k];
			darr[k]=darr[k+1];
			darr[k+1]=t;
		}
	}
}

__global__ void odd(int *darr,int *n)
{
	int k=threadIdx.x;
	k=k*2+1;
	if(k<=n-2)
	{
		if(darr[k]>drr[k+1])
		{
			int t=darr[k];
			darr[k]=darr[k+1];
			darr[k+1]=t;
		}
	}
}

__global__ void odd(int *arr,int n)
{
	
}

int main()
{
	int *arr,*darr;
	int n;
	printf("\n Enter the size of array :" );
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("After Sorting");
	for(int i=0;i<n;i++)
	{
		printf(" %d ",arr[i]);	
	}
	cudaMalloc(&darr,n*sizeof(int));
	cudaMemcpy(darr,arr,n*sizeof(int),cudaMemcpyHostToDevice);
	for(int i=0;i<n/2;i++)
	{
		even<<<1,n>>>(darr,n);
		odd<<<1,n>>>(darr,n)
	}
	cudaMemcpy(arr,darr,n*sizeof(int),cudaMemcpyDeviceToHost);
	printf("After Sorting");
	for(int i=0;i<n;i++)
	{
		printf(" %d ",arr[i]);	
	}
	
}
