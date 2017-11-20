#include<stdio.h>
int display(char arr[])
{
	printf("________________\n");
	printf("|  %c |  %c |  %c |\n",arr[0],arr[1],arr[2]);
	printf("________________\n");
	printf("|  %c |  %c |  %c |\n",arr[3],arr[4],arr[5]);
	printf("________________\n");
	printf("|  %c |  %c |  %c |\n",arr[6],arr[7],arr[8]);
	printf("________________\n");	
}
int  check(char arr[])
{
	if(arr[0]==arr[1] && arr[1]==arr[2])
	return 0;
	if(arr[3]==arr[4] && arr[4]==arr[5])
	return 0;
	if(arr[6]==arr[7] && arr[7]==arr[8])
	return 0;
	if(arr[0]==arr[3] && arr[3]==arr[6])
	return 0;
	if(arr[1]==arr[4] && arr[4]==arr[7])
	return 0;
	if(arr[2]==arr[5] && arr[5]==arr[8])
	return 0;
	if(arr[0]==arr[4] && arr[4]==arr[8])
	return 0;
	if(arr[2]==arr[4] && arr[4]==arr[6])
	return 0;
	else
	return 1;
}
int main()
{
 char arr[]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
 char tem[]={'0','1','2','3','4','5','6','7','8'};
 printf("player 1=X and player 2=O \n");
 int turn=1,ch=0;
 int win=1;
 while(win)
 {
 	if(turn==1)
 	{
 		display(arr);
 		printf("player 1 turn -X \n");
 		printf("Enter the selection -\n");
 		display(tem);
 		scanf("%d",&ch);
 		arr[ch]='X';
 		tem[ch]='X';
 		win=check(tem);
 		turn=2;	
 	}
 	else
	{
 		display(arr);
 		printf("player 2 turn -O \n");
 		printf("Enter the selection -\n");
 		display(tem);
 		scanf("%d",&ch);
 		arr[ch]='O';
 		tem[ch]='O';
 		win=check(tem);
 		turn=1;	
 	}
}
if(turn!=1)
{
	printf("player 1 wins");
}
else
{
	display(arr);
	printf("player 2 wins");
}
return 0;
}
