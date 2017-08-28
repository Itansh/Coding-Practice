// 3.	Find a pair in an array of size 'n', whose sum is X
#include<stdio.h>
#include<conio.h>
int main()
{   int x=6;
	int arr[10]={1,2,3,4,5,6,7,8,9,0};
	for(int i=0;i<10;i++)
	{
		for(int j=i+1;j<10;j++)
		{
			if(arr[i]+arr[j]==x)
			{
				printf("(%d,%d),",arr[i],arr[j]);
			}
		}
	}
}
// time complexity O(n^2);
// if i apply it on sorted array then i can find the number which is greater then the sum need to be analized
