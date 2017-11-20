#include<stdio.h>
int x=0,y=0;
int solution1(int xmax,int ymax,int n)
{
	int step1=0;
	x=0,y=0;
	while(x!=n)
	{
		int temp=0;
		if(x==0)
		{
			printf("if x==%d then ",x);
			x=xmax;
			printf("x=%d \n",xmax);
		}
		if(y==ymax)
		{
			printf("if y==%d then ",ymax);
			y=0;
			printf("y=0 \n");
		}
		if(ymax-y<x)
			temp=ymax-y;
		else
			temp=x;	
		x=x-temp; printf("New x=%d \n",x );
		y=y+temp; printf("New y=%d \n",y);
		step1++;
	}
	printf("steps required by solution 1 = %d \n", step1 );
	return step1;
}
int solution2(int xmax,int ymax,int n)
{
	x=0,y=0;
	int step2=0;
	while(x!=n)
	{
		int temp=0;
		if(y==0)
		{
			printf("if x==%d then ",x);
			y=ymax;
			printf("x=%d \n",xmax);
		}
		if(x==xmax)
		{
			printf("if y==%d then ",ymax);
			x=0;
			printf("y=0 \n");
		}
		if(xmax-x<y)
			temp=xmax-x;
		else
			temp=y;	
		y=y-temp; printf("New y=%d \n",x );
		x=x+temp; printf("New x=%d \n",y);
		step2++;
	}
	printf("steps required by solution 2 = %d \n", step2 );
	return step2;
}
int main()
{
int xmax,ymax,n,step1,step2;
printf("Enter maximum values of jug 1 nad jug 2 \n");
scanf("%d %d",&xmax,&ymax);
printf("Enter goal \n");
scanf("%d",&n);
step1=solution1(xmax,ymax,n);
step2=solution2(xmax,ymax,n);
if(step1>step2)
{
	printf("Solution 2 is better ");
}
else printf("solution 1 is better");

}
